#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define ARR_INT(arr) ((unsigned char *)arr)
#define ARR_STR(arr) ((char **)arr)
#define MAX_ARR	50
#define MAX_STR 50
#define BILLION 10000000
#define FUNC_NUM 5
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )


typedef enum {FALSE, TRUE} BOOL;

static char s[MAX_STR];

typedef struct {
	unsigned char front, rear;
	unsigned char size; // queue size 
	void *queue; // queue array
} QueueType;

void qu_init(QueueType *qu, unsigned int n, BOOL isNum) {
	//front == rear �̸� ����ִ�.
	//rear + 1 == front �̸� �� ���ִ�.
	int i;
	qu->front = 0;
	qu->rear = 0;
	qu->size = n + 1;
	if (isNum) {
		qu->queue = ((unsigned char *)malloc(sizeof(unsigned char) * qu->size));
	}
	else {
		qu->queue = (char **)malloc(sizeof(char *) * qu->size);
		for (i = 0; i < qu->size; i++) {
			ARR_STR(qu->queue)[i] = (char *)malloc(sizeof(char) * MAX_STR);
		}
	}
}

void qu_push(QueueType *qu, void *v, BOOL isNum) {
	//ť�� �� ���ִٸ� ���� �� ����.
	if (qu->rear + 1 == qu->front)
		return;
	if (isNum) {
		ARR_INT(qu->queue)[qu->rear] = (unsigned char)v;
		qu->rear = (qu->rear + 1) % qu->size;
	}
	else {
		strcpy(ARR_STR(qu->queue)[qu->rear], (char *)v);
		qu->rear = (qu->rear + 1) % qu->size;
	}
}

void *qu_pop(QueueType *qu, BOOL isNum) {
	unsigned char v;
	
	//ť�� ����ִٸ� �� �� ����.
	if (qu->rear == qu->front)
		return;

	if (isNum) {
		v = ARR_INT(qu->queue)[qu->front];
		qu->front = (qu->front + 1) % qu->size;
		return v;
	}
	else {
		strcpy(s, ARR_STR(qu->queue)[qu->front]);
		qu->front = (qu->front + 1) % qu->size;
		return s;
	}


	
}

typedef struct {
	void *heap;
	unsigned char heap_size;
} HeapType;
// �ʱ�ȭ �Լ�
init(HeapType *h, BOOL isNum)
{
	int i;
	h->heap_size = 0;
	if (isNum) {
		h->heap = (unsigned char *)malloc(sizeof(unsigned char) * MAX_ARR);
	}
	else {
		h->heap = (char **)malloc(sizeof(char *) * MAX_ARR);
		for (i = 0; i < MAX_ARR; i++) {
			ARR_STR(h->heap)[i] = (char *)malloc(sizeof(char) * MAX_STR);
		}
	}
}


void insert_max_heap(HeapType *h, void *item, BOOL isNum)
{
	int i;
	i = ++(h->heap_size);

	if (isNum) {
		//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
		while ((i != 1) && ((unsigned char)item > ARR_INT(h->heap)[i / 2])) {
			ARR_INT(h->heap)[i] = ARR_INT(h->heap)[i / 2];
			i /= 2;
		}

		ARR_INT(h->heap)[i] = (unsigned char)item;     // ���ο� ��带 ����
	}
	else {
		//  Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
		while ((i != 1) && CompareStr((char *)item, ARR_STR(h->heap)[i / 2]) == 0) {
			strcpy(ARR_STR(h->heap)[i],ARR_STR(h->heap)[i / 2]);
			i /= 2;
		}

		strcpy(ARR_INT(h->heap)[i],(char *)item);     // ���ο� ��带 ����
	}
}

void *delete_max_heap(HeapType *h, BOOL isNum)
{
	unsigned char parent, child;
	void *item, *temp;

	if (isNum) {
		item = ARR_INT(h->heap)[1];
		temp = ARR_INT(h->heap)[(h->heap_size)--];
		parent = 1;
		child = 2;
		while (child <= h->heap_size) {
			if ((child < h->heap_size) &&
				(ARR_INT(h->heap)[child]) < ARR_INT(h->heap)[child + 1])
				child++;
			if ((unsigned char)temp >= ARR_INT(h->heap)[child]) break;
			// �Ѵܰ� �Ʒ��� �̵�
			ARR_INT(h->heap)[parent] = ARR_INT(h->heap)[child];
			parent = child;
			child *= 2;
		}
		ARR_INT(h->heap)[parent] = (unsigned char)temp;
		return item;
	}
	else {
		char tempStr[MAX_STR];
		strcpy(s, ARR_STR(h->heap)[1]);
		strcpy(tempStr, ARR_STR(h->heap)[(h->heap_size)--]);
		parent = 1;
		child = 2;
		while (child <= h->heap_size) {
			// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
			if ((child < h->heap_size) &&
				CompareStr(ARR_STR(h->heap)[child], ARR_STR(h->heap)[child + 1]) == 1)
				child++;
			if (CompareStr(tempStr, ARR_STR(h->heap)[child]) != 1) break;
			// �Ѵܰ� �Ʒ��� �̵�
			strcpy(ARR_STR(h->heap)[parent], ARR_STR(h->heap)[child]);
			parent = child;
			child *= 2;
		}
		strcpy(ARR_STR(h->heap)[parent], tempStr);
		return s;
	}
}


int CompareStr(char *str1, char *str2) {
	//���� ���ڿ��� �� ũ��			0
	//������ ���ڿ��� �� ũ��		1
	//�� ���ڿ��� ������			2
	int i= 0;
	while (1) {
		if (str1[i] == '\0' && str2[i] == '\0') return 2;

		if (str1[i] == str2[i]) i++;
		else if (str1[i] > str2[i]) return 0;
		else if (str1[i] < str2[i]) return 1;
	}
}

void SwapStr(char *str1, char *str2) {
	char temp[MAX_STR];
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
}

void PrintArr(void *arr, unsigned int count, BOOL isNum) {
	int i;
	for (i = 0; i < count; i++) {
		if (isNum)printf("%d ", ARR_INT(arr)[i]);
		else printf("%s ", ARR_STR(arr)[i]);
	}
	printf("\n");
}

void SelectSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	int i, j, dst, temp;
	if (isNum) {
		for (i = 0; i < count - 1; i++) {
			dst = i;
			for (j = i + 1; j < count; j++) 			
				if (isAscending && ARR_INT(arr)[j] < ARR_INT(arr)[dst]) dst = j;
				else if (!isAscending && ARR_INT(arr)[j] > ARR_INT(arr)[dst]) dst = j;
			SWAP(ARR_INT(arr)[i], ARR_INT(arr)[dst], temp);
			if (doPrint) {
				printf("SelectSort : ");
				PrintArr(arr, count, isNum);
			}
		}
	}
	else {
		for (i = 0; i < count - 1; i++) {
			dst = i;
			for (j = i + 1; j < count; j++) 			
				if (isAscending && CompareStr(ARR_STR(arr)[j],ARR_STR(arr)[dst]) == 1) dst = j;
				else if (!isAscending && CompareStr(ARR_STR(arr)[j], ARR_STR(arr)[dst]) == 0) dst = j;
			SwapStr(ARR_INT(arr)[i], ARR_INT(arr)[dst]);
			if (doPrint) {
				printf("SelectSort : ");
				PrintArr(arr, count, isNum);
			}
		}
	}
}

void InsertSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	int i, j, key;
	char keyStr[MAX_STR];
	if (isNum) {
		for (i = 1; i < count; i++) {
			key = ARR_INT(arr)[i];
			if (isAscending) {
				for (j = i - 1; j >= 0 && ARR_INT(arr)[j] > key; j--)
					ARR_INT(arr)[j + 1] = ARR_INT(arr)[j];
			}
			else {
				for (j = i - 1; j >= 0 && ARR_INT(arr)[j] < key; j--)
					ARR_INT(arr)[j + 1] = ARR_INT(arr)[j];
			}
			ARR_INT(arr)[j + 1] = key;
			if (doPrint) {
				printf("InsertSort : ");
				PrintArr(arr, count, isNum);
			}
		}
	}
	else {
		for (i = 1; i < count; i++) {
			strcpy(keyStr, ARR_STR(arr)[i]);
			if (isAscending) {
				for (j = i - 1; j >= 0 && CompareStr(ARR_STR(arr)[j],keyStr) == 0; j--)
					strcpy(ARR_STR(arr)[j + 1],ARR_STR(arr)[j]);
			}
			else {
				for (j = i - 1; j >= 0 && CompareStr(ARR_STR(arr)[j],keyStr) == 1; j--)
					strcpy(ARR_STR(arr)[j + 1],ARR_STR(arr)[j]);
			}
			strcpy(ARR_INT(arr)[j + 1],keyStr);
			if (doPrint) {
				printf("InsertSort : ");
				PrintArr(arr, count, isNum);
			}
		}
	}

}

void BubbleSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	int i, j, temp;
	if (isNum) {
		for (i = count - 1; i > 0; i--) {
			for (j = 0; j < i; j++)
				if (isAscending) {
					if (ARR_INT(arr)[j] > ARR_INT(arr)[j + 1]) {
						SWAP(ARR_INT(arr)[j], ARR_INT(arr)[j + 1], temp);
						if (doPrint) {
							printf("BubbleSort : ");
							PrintArr(arr, count, isNum);
						}
					}
				}
				else {
					if (ARR_INT(arr)[j] < ARR_INT(arr)[j + 1]) {
						SWAP(ARR_INT(arr)[j], ARR_INT(arr)[j + 1], temp);
						if (doPrint) {
							printf("BubbleSort : ");
							PrintArr(arr, count, isNum);
						}
					}
				}
		}
	}
	else {
		for (i = count - 1; i > 0; i--) {
			for (j = 0; j < i; j++)
				if (isAscending) {
					if (CompareStr(ARR_STR(arr)[j], ARR_STR(arr)[j + 1]) == 0) {
						SwapStr(ARR_STR(arr)[j], ARR_STR(arr)[j + 1]);
						if (doPrint) {
							printf("BubbleSort : ");
							PrintArr(arr, count, isNum);
						}
					}
				}
				else {
					if (CompareStr(ARR_STR(arr)[j], ARR_STR(arr)[j + 1]) == 1) {
						SwapStr(ARR_STR(arr)[j], ARR_STR(arr)[j + 1]);
						if (doPrint) {
							printf("BubbleSort : ");
							PrintArr(arr, count, isNum);
						}
					}
				}
		}
	}

}

void merge(void *arr, unsigned char left, unsigned char mid, unsigned char right, BOOL isAscending, BOOL isNum, unsigned char count, BOOL doPrint)
{	
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	if (isNum) {
		unsigned char sortedInt[MAX_ARR];

		// ���� ���ĵ� list�� �պ�
		while (i <= mid && j <= right) {
			if (isAscending) {
				if (ARR_INT(arr)[i] <= ARR_INT(arr)[j]) sortedInt[k++] = ARR_INT(arr)[i++];
				else sortedInt[k++] = ARR_INT(arr)[j++];
			}
			else {
				if (ARR_INT(arr)[i] >= ARR_INT(arr)[j]) sortedInt[k++] = ARR_INT(arr)[i++];
				else sortedInt[k++] = ARR_INT(arr)[j++];
			}
		}

		if (i > mid)    // ���� �ִ� ���ڵ��� �ϰ� ����
			for (l = j; l <= right; l++)
				sortedInt[k++] = ARR_INT(arr)[l];
		else 	   // ���� �ִ� ���ڵ��� �ϰ� ����
			for (l = i; l <= mid; l++)
				sortedInt[k++] = ARR_INT(arr)[l];

		// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
		for (l = left; l <= right; l++)
			ARR_INT(arr)[l] = sortedInt[l];
		if (doPrint) {
			printf("MergeSort : ");
			PrintArr(arr, count, isNum);
		}
	}
	else {
		char sortedStr[MAX_ARR][MAX_STR];
		// ���� ���ĵ� list�� �պ�
		while (i <= mid && j <= right) {
			if (isAscending) {
				if (CompareStr(ARR_STR(arr)[i], ARR_STR(arr)[j]) == 1) strcpy(sortedStr[k++], ARR_STR(arr)[i++]);
				else strcpy(sortedStr[k++],ARR_STR(arr)[j++]);
			}
			else {
				if (CompareStr(ARR_STR(arr)[i], ARR_STR(arr)[j]) == 0) strcpy(sortedStr[k++], ARR_STR(arr)[i++]);
				else strcpy(sortedStr[k++], ARR_STR(arr)[j++]);
			}
		}

		if (i > mid)    // ���� �ִ� ���ڵ��� �ϰ� ����
			for (l = j; l <= right; l++)
				strcpy(sortedStr[k++],ARR_INT(arr)[l]);
		else 	   // ���� �ִ� ���ڵ��� �ϰ� ����
			for (l = i; l <= mid; l++)
				strcpy(sortedStr[k++], ARR_INT(arr)[l]);

		// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
		for (l = left; l <= right; l++)
			strcpy(ARR_STR(arr)[l],sortedStr[l]);
		if (doPrint) {
			printf("MergeSort : ");
			PrintArr(arr, count, isNum);
		}
	}
}

void merge_sort(void *arr, unsigned char left, unsigned char right, BOOL isAscending, BOOL isNum, unsigned char count, BOOL doPrint)
{
	unsigned char mid;

	if (left < right) {
		mid = (left + right) / 2;         // ����Ʈ�� �յ� ����
		merge_sort(arr, left, mid, isAscending, isNum, count, doPrint);    // �κи���Ʈ ����
		merge_sort(arr, mid + 1, right, isAscending, isNum, count, doPrint);//�κи���Ʈ ����
		merge(arr, left, mid, right, isAscending, isNum, count, doPrint);   // �պ�
	}
}


void MergeSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	merge_sort(arr, 0, count-1, isAscending, isNum, count, doPrint);
}

void HeapSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	int i;
	HeapType h;
	if (isNum) {
		init(&h, isNum);
		for (i = 0; i < count; i++) {
			insert_max_heap(&h, ARR_INT(arr)[i], isNum);
		}
		if (isAscending) {
			for (i = (count - 1); i >= 0; i--) {
				ARR_INT(arr)[i] = delete_max_heap(&h, isNum);
				if (doPrint) {
					printf("HeapSort : ");
					PrintArr(arr, count, isNum);
				}
			}
		}
		else {
			for (i = 0; i < count; i++) {
				ARR_INT(arr)[i] = delete_max_heap(&h, isNum);
				if (doPrint) {
					printf("HeapSort : ");
					PrintArr(arr, count, isNum);
				}
			}
		}
	}
	else {
		init(&h, isNum);
		for (i = 0; i < count; i++) {
			insert_max_heap(&h, ARR_STR(arr)[i], isNum);
		}
		if (isAscending) {
			for (i = (count - 1); i >= 0; i--) {
				strcpy(ARR_STR(arr)[i], delete_max_heap(&h, isNum));
				if (doPrint) {
					printf("HeapSort : ");
					PrintArr(arr, count, isNum);
				}
			}
		}
		else {
			for (i = 0; i < count; i++) {
				strcpy(ARR_STR(arr)[i], delete_max_heap(&h, isNum));
				if (doPrint) {
					printf("HeapSort : ");
					PrintArr(arr, count, isNum);
				}
			}
		}
	}

}

unsigned char partition(void *arr,int left,int right, int count, BOOL isAscending, BOOL isNum, BOOL doPrint)
{
	unsigned char pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	if (isNum) {
		pivot = ARR_INT(arr)[left];
		do {
			if (isAscending) {
				do
					low++;
				while (low <= right && ARR_INT(arr)[low] < pivot);
				do
					high--;
				while (high >= left && ARR_INT(arr)[high] > pivot);
			}
			else {
				do
					low++;
				while (low <= right && ARR_INT(arr)[low] > pivot);
				do
					high--;
				while (high >= left && ARR_INT(arr)[high] < pivot);
			}
			if (low < high) {
				SWAP(ARR_INT(arr)[low], ARR_INT(arr)[high], temp);
				if (doPrint) {
					printf("QuickSort : ");
					PrintArr(arr, count, isNum);
				}
			}
		} while (low < high);

		SWAP(ARR_INT(arr)[left], ARR_INT(arr)[high], temp);
		if (doPrint) {
			printf("QuickSort : ");
			PrintArr(arr, count, isNum);
		}
	}
	else {
		char pivotStr[MAX_STR];
		strcpy(pivotStr, ARR_STR(arr)[left]);
		do {
			if (isAscending) {
				do
					low++;
				while (low <= right && CompareStr(ARR_STR(arr)[low], pivotStr) == 1);
				do
					high--;
				while (high >= left && CompareStr(ARR_STR(arr)[high], pivotStr) == 0);
			}
			else {
				do
					low++;
				while (low <= right && CompareStr(ARR_STR(arr)[low], pivotStr) == 0);
				do
					high--;
				while (high >= left && CompareStr(ARR_STR(arr)[high], pivotStr) == 1);
			}
			if (low < high) {
				SwapStr(ARR_STR(arr)[low], ARR_STR(arr)[high]);
				if (doPrint) {
					printf("QuickSort : ");
					PrintArr(arr, count, isNum);
				}
			}
		} while (low < high);

		SwapStr(ARR_STR(arr)[left], ARR_STR(arr)[high]);
		if (doPrint) {
			printf("QuickSort : ");
			PrintArr(arr, count, isNum);
		}
	}

	return high;
}


void quick_sort(void *arr,int left,int right, int count, BOOL isAscending, BOOL isNum, BOOL doPrint)
{
	if (left < right) {
		unsigned int q = partition(arr, left, right, count, isAscending, isNum, doPrint);
		quick_sort(arr, left, q - 1, count, isAscending, isNum, doPrint);
		quick_sort(arr, q + 1, right, count, isAscending, isNum, doPrint);
	}
}

void QuickSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	quick_sort(arr, 0, count - 1, count, isAscending, isNum, doPrint);
}

void ShellSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	int i, j, k, gap, key, first, last;
	char keyStr[MAX_STR];
	if (isNum) {
		for (gap = count / 2; gap > 0; gap = gap / 2) {
			if ((gap % 2) == 0) gap++;
			for (i = 0; i < gap; i++) {
				first = i;
				last = count - 1;
				for (k = first + gap; k <= last; k = k + gap) {
					key = ARR_INT(arr)[k];
					if (isAscending) {
						for (j = k - gap; j >= first && key < ARR_INT(arr)[j]; j = j - gap)
							ARR_INT(arr)[j + gap] = ARR_INT(arr)[j];
					}
					else {
						for (j = k - gap; j >= first && key > ARR_INT(arr)[j]; j = j - gap)
							ARR_INT(arr)[j + gap] = ARR_INT(arr)[j];
					}
					ARR_INT(arr)[j + gap] = key;
					if (doPrint) {
						printf("ShellSort : ");
						PrintArr(arr, count, isNum);
					}
				}
			}
		}
	}
	else {
		for (gap = count / 2; gap > 0; gap = gap / 2) {
			if ((gap % 2) == 0) gap++;
			for (i = 0; i < gap; i++) {
				first = i;
				last = count - 1;
				for (k = first + gap; k <= last; k = k + gap) {
					strcpy(keyStr, ARR_STR(arr)[k]);
					if (isAscending) {
						for (j = k - gap; j >= first && CompareStr(keyStr, ARR_STR(arr)[j]) == 1; j = j - gap)
							strcpy(ARR_STR(arr)[j + gap], ARR_STR(arr)[j]);
					}
					else {
						for (j = k - gap; j >= first && CompareStr(keyStr, ARR_STR(arr)[j]) == 0; j = j - gap)
							strcpy(ARR_STR(arr)[j + gap], ARR_STR(arr)[j]);
					}
					strcpy(ARR_STR(arr)[j + gap], keyStr);
					if (doPrint) {
						printf("ShellSort : ");
						PrintArr(arr, count, isNum);
					}
				}
			}
		}
	}

}

void RadixSort(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint) {
	int i, b, d, factor = 1, maxNum = 0, digits = 0;
	char maxStr[MAX_STR];
	QueueType queues[27];
	if (isNum) {
		for (i = 0; i < MAX_ARR; i++) {
			if (ARR_INT(arr)[i] > maxNum) maxNum = ARR_INT(arr)[i];
		}

		digits = (unsigned char)log(maxNum);

		for (b = 0; b < 10; b++) qu_init(&queues[b], MAX_ARR, isNum);	// ť���� �ʱ�ȭ

		for (d = 0; d < digits; d++) {
			for (i = 0; i < count; i++)				// �����͵��� �ڸ����� ���� ť�� �Է�
				qu_push(&queues[(ARR_INT(arr)[i] / factor) % 10], ARR_INT(arr)[i], isNum);
			if (isAscending) {
				for (b = 0, i = 0; b < 10; b++)			// ���Ͽ��� ������ list�� ��ģ��.
					while (!((&queues[b])->rear == (&queues[b])->front))
						ARR_INT(arr)[i++] = qu_pop(&queues[b], isNum);
			}
			else {
				for (b = 9, i = 0; b >= 0; b--)			// ���Ͽ��� ������ list�� ��ģ��.
					while (!((&queues[b])->rear == (&queues[b])->front))
						ARR_INT(arr)[i++] = qu_pop(&queues[b], isNum);
			}
			if (doPrint) {
				printf("RadixSort : ");
				PrintArr(arr, count, isNum);
			}
			factor *= 10;				// �� ���� �ڸ����� ����.
		}
	}
	else {
		unsigned char j = 0;
		for (i = 0; i < count; i++) {
			j = 0;
			while (1) {
				if (ARR_STR(arr)[i][j] != '\0') j++;
				else break;
			}
			if (j > digits) digits = j;
		}

		for (b = 0; b < 27; b++) qu_init(&queues[b], MAX_ARR, isNum);	// ť���� �ʱ�ȭ

		for (d = 0; d < digits; d++) {
			unsigned char idx;
			for (i = 0; i < count; i++) {				// �����͵��� �ڸ����� ���� ť�� �Է�
				idx = ARR_STR(arr)[i][j] - 'a' + 1;
				if (idx < 0) idx = 0;
				qu_push(&queues[idx], ARR_STR(arr)[i], isNum);
			}
			if (isAscending) {
				for (b = 0, i = 0; b < 27; b++)			// ���Ͽ��� ������ list�� ��ģ��.
					while (!((&queues[b])->rear == (&queues[b])->front)) {
						strcpy(ARR_STR(arr)[i++], qu_pop(&queues[b], isNum));
					}
			}
			else {
				for (b = 26, i = 0; b >= 0; b--)			// ���Ͽ��� ������ list�� ��ģ��.
					while (!((&queues[b])->rear == (&queues[b])->front)) {
						strcpy(ARR_STR(arr)[i++], qu_pop(&queues[b], isNum));
					}
			}

			if (doPrint) {
				printf("RadixSort : ");
				PrintArr(arr, count, isNum);
			}
			j--;				// �� ���� �ڸ����� ����.
		}
	}

}

clock_t FuctionTimer(void *arr, unsigned int count, BOOL isAscending, BOOL isNum, BOOL doPrint ,void (*fp)(void *,unsigned char, BOOL, BOOL, BOOL)) {
	clock_t start, end, gap;
	start = clock();
	(*fp)(arr, count, isAscending, isNum, FALSE);
	end = clock();
	gap = end - start;
	return gap;
}

void *InitArr(BOOL isNum) {
	void *arr;
	int i;
	if (isNum == TRUE) {
		arr = (unsigned char *)malloc(sizeof(unsigned char) * MAX_ARR);
	}
	else {
		arr = (char **)malloc(sizeof(char *) * MAX_ARR);
		for (i = 0; i < MAX_ARR; i++) {
			ARR_STR(arr)[i] = (char *)malloc(sizeof(char) * MAX_STR);
		}
	}
	return arr;
}

void CreateRandArr(unsigned char *arr, unsigned int num) {
	unsigned char random = 1;
	int i;
	srand(time(NULL));
	clock_t start = clock();
	for (i = 0; i < num; i++) {
		random = (rand()%256);
		arr[i] = random;
	}
	clock_t end = clock();
	printf("�迭 ���� �ҿ� �ð� : %d(ms)\n", end - start);
}


void CompareSortingTime() {
	clock_t gap[FUNC_NUM];
	unsigned char arr[BILLION];
	unsigned int num = BILLION;
	int i;
	void(*fp[FUNC_NUM]) (void *, unsigned char, BOOL, BOOL, BOOL) = {
	&SelectSort, &InsertSort,
	&BubbleSort,
	&QuickSort, &ShellSort };

	printf("�迭 ���� ��...\n");
	CreateRandArr(arr, num);
	printf("�迭 ���� �Ϸ�!!!\n");

	printf("���� ��...\n");

	for (i = 0; i < FUNC_NUM; i++) {
		gap[i] = FuctionTimer(arr, num, TRUE, TRUE, FALSE, fp[i]);
		printf("%.3lf%% ������\n", (double)i / FUNC_NUM * 100);
	}
	printf("���� �Ϸ�!!!\n");

	//system("cls");
	printf("--------------------------------------------\n");
	printf("���� ���� �ð� ��\n");
	printf("%d���� ������ ���\n", BILLION);
	printf("Select Sort : %d(ms)\n", gap[0]);
	printf("Insert Sort : %d(ms)\n", gap[1]);
	printf("Bubble Sort : %d(ms)\n", gap[2]);
	printf("Quick Sort  : %d(ms)\n", gap[3]);
	printf("Shell Sort  : %d(ms)\n", gap[4]);
//	printf("Merge Sort  : %.3f\n", gap[3]);
//	printf("Heap Sort   : %.3f\n", gap[4]);
//	printf("Radix Sort  : %.3f\n", gap[5]);
	printf("--------------------------------------------\n");
	printf("�Ϸ�Ǿ����ϴ�!!!\n");
	rewind(stdin);
	getchar();
}

void Run() {
	FILE *fp;
	char filename[MAX_STR];
	int count = 1;
	char cmd = '0';
	BOOL isAscending = TRUE;
	BOOL isNum = TRUE;
	BOOL isSTI = TRUE;
	void *myArr;
	int i;

	while (cmd != 'x') {
		//���ڿ� Ȥ�� ���� ó��
		system("cls");
		printf("------------------------\n");
		printf("������ ��\n");
		printf("����   : 1\n");
		printf("���ڿ� : 2\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();
		if (cmd == '1')
			isNum = TRUE;
		else if (cmd == '2')
			isNum = FALSE;
		myArr = InitArr(isNum);

		//������ ���� ó��
		system("cls");
		printf("------------------------\n");
		printf("�Է� ���\n");
		printf("ǥ�� �Է� : 1\n");
		printf("����      : 2\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();

		if (cmd == '1') {
			isSTI = TRUE;
		}
		else if (cmd == '2') {
			isSTI = FALSE;
			printf("������ ���� �̸� : ");
			rewind(stdin);
			gets_s(filename, sizeof(filename));
			if (isNum) {
				fp = fopen(filename, "r");
				for (i = 0; i <= count; i++) {
					if (i == 0) {
						fscanf(fp, "%d\n", &count);
						continue;
					}
					fscanf(fp, "%d\n", ARR_INT(myArr) + (i - 1));
				}	
			}
			else {
				fp = fopen(filename, "r");
				for (i = 0; i <= count; i++) {
					if (i == 0) {
						fscanf(fp, "%d", &count);
						continue;
					}
					fscanf(fp, "%s", ARR_STR(myArr)[i - 1]);
				}
			}
		}

		//��������, �������� ����
		system("cls");
		printf("------------------------\n");
		printf("���� ���\n");
		printf("���� ���� : 1\n");
		printf("���� ���� : 2\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();

		if (cmd == '1') {
			isAscending = TRUE;
		}
		else if (cmd == '2') {
			isAscending = FALSE;
		}

		//���� ����
		printf("------------------------\n");
		printf("����� ����\n");
		printf("���� ���� : s\n");
		printf("���� ���� : i\n");
		printf("���� ���� : b\n");
		printf("�պ� ���� : m\n");
		printf("���� ���� : h\n");
		printf("��� ���� : r\n");
		printf("�� ����   : q\n");
		printf("�� ����   : l\n");
		printf("���Ľð� �� : t\n");
		printf("���α׷� ���� : x\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();

		if (cmd == 't') {
			CompareSortingTime();
			continue;
		}

		//ǥ�� �Է�(������ ������ ����Ǿ� ���� ��� �� ���� ����)
		if (isSTI && cmd != 'x') {
			char myStr[MAX_STR];
			count = 0;
			printf("------------------------------\n");
			printf("�ִ� 50������ ��� �����մϴ�.\n");
			printf("�Է��� ���� �� =�� �Է��ϼ���.\n");
			rewind(stdin);
			if (isNum) {
				unsigned char num;
				for (i = 0; i < MAX_ARR; i++) {
					printf("���� �Է� (%d/50) : ", count);
					gets_s(myStr, sizeof(myStr));
					if (strcmp(myStr, "=") == 0) break;
					num = atoi(myStr);
					ARR_INT(myArr)[i] = num;
					count++;
				}
			}
			else {
				for (i = 0; i < MAX_ARR; i++) {
					printf("���ڿ� �Է� (%d/50) : ", count);
					gets_s(myStr, sizeof(myStr));
					if (strcmp(myStr,"=") == 0) break;
					memset(ARR_STR(myArr)[i], 0, sizeof(myStr));
					strcpy(ARR_STR(myArr)[i], myStr);
					count++;
				}
			}
			printf("------------------------------\n");
		}

		//�Լ� ����
		switch (cmd) {
		case 's':
			SelectSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'i':
			InsertSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'b':
			BubbleSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'm':
			MergeSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'h':
			HeapSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'r':
			RadixSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'q':
			QuickSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'l':
			ShellSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***������ �Ϸ�Ǿ����ϴ�.***\n");
			getchar();
			break;
		case 'x':
			exit(0);
		}
	}
}


int main() {
	Run();
}
