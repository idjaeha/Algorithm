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
	//front == rear 이면 비어있다.
	//rear + 1 == front 이면 꽉 차있다.
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
	//큐가 꽉 차있다면 넣을 수 없다.
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
	
	//큐가 비어있다면 뺄 수 없다.
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
// 초기화 함수
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
		//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
		while ((i != 1) && ((unsigned char)item > ARR_INT(h->heap)[i / 2])) {
			ARR_INT(h->heap)[i] = ARR_INT(h->heap)[i / 2];
			i /= 2;
		}

		ARR_INT(h->heap)[i] = (unsigned char)item;     // 새로운 노드를 삽입
	}
	else {
		//  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
		while ((i != 1) && CompareStr((char *)item, ARR_STR(h->heap)[i / 2]) == 0) {
			strcpy(ARR_STR(h->heap)[i],ARR_STR(h->heap)[i / 2]);
			i /= 2;
		}

		strcpy(ARR_INT(h->heap)[i],(char *)item);     // 새로운 노드를 삽입
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
			// 한단계 아래로 이동
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
			// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
			if ((child < h->heap_size) &&
				CompareStr(ARR_STR(h->heap)[child], ARR_STR(h->heap)[child + 1]) == 1)
				child++;
			if (CompareStr(tempStr, ARR_STR(h->heap)[child]) != 1) break;
			// 한단계 아래로 이동
			strcpy(ARR_STR(h->heap)[parent], ARR_STR(h->heap)[child]);
			parent = child;
			child *= 2;
		}
		strcpy(ARR_STR(h->heap)[parent], tempStr);
		return s;
	}
}


int CompareStr(char *str1, char *str2) {
	//왼쪽 문자열이 더 크면			0
	//오른쪽 문자열이 더 크면		1
	//두 문자열이 같으면			2
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

		// 분할 정렬된 list의 합병
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

		if (i > mid)    // 남아 있는 레코드의 일괄 복사
			for (l = j; l <= right; l++)
				sortedInt[k++] = ARR_INT(arr)[l];
		else 	   // 남아 있는 레코드의 일괄 복사
			for (l = i; l <= mid; l++)
				sortedInt[k++] = ARR_INT(arr)[l];

		// 배열 sorted[]의 리스트를 배열 list[]로 복사
		for (l = left; l <= right; l++)
			ARR_INT(arr)[l] = sortedInt[l];
		if (doPrint) {
			printf("MergeSort : ");
			PrintArr(arr, count, isNum);
		}
	}
	else {
		char sortedStr[MAX_ARR][MAX_STR];
		// 분할 정렬된 list의 합병
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

		if (i > mid)    // 남아 있는 레코드의 일괄 복사
			for (l = j; l <= right; l++)
				strcpy(sortedStr[k++],ARR_INT(arr)[l]);
		else 	   // 남아 있는 레코드의 일괄 복사
			for (l = i; l <= mid; l++)
				strcpy(sortedStr[k++], ARR_INT(arr)[l]);

		// 배열 sorted[]의 리스트를 배열 list[]로 복사
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
		mid = (left + right) / 2;         // 리스트의 균등 분할
		merge_sort(arr, left, mid, isAscending, isNum, count, doPrint);    // 부분리스트 정렬
		merge_sort(arr, mid + 1, right, isAscending, isNum, count, doPrint);//부분리스트 정렬
		merge(arr, left, mid, right, isAscending, isNum, count, doPrint);   // 합병
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

		for (b = 0; b < 10; b++) qu_init(&queues[b], MAX_ARR, isNum);	// 큐들의 초기화

		for (d = 0; d < digits; d++) {
			for (i = 0; i < count; i++)				// 데이터들을 자리수에 따라 큐에 입력
				qu_push(&queues[(ARR_INT(arr)[i] / factor) % 10], ARR_INT(arr)[i], isNum);
			if (isAscending) {
				for (b = 0, i = 0; b < 10; b++)			// 버켓에서 꺼내어 list로 합친다.
					while (!((&queues[b])->rear == (&queues[b])->front))
						ARR_INT(arr)[i++] = qu_pop(&queues[b], isNum);
			}
			else {
				for (b = 9, i = 0; b >= 0; b--)			// 버켓에서 꺼내어 list로 합친다.
					while (!((&queues[b])->rear == (&queues[b])->front))
						ARR_INT(arr)[i++] = qu_pop(&queues[b], isNum);
			}
			if (doPrint) {
				printf("RadixSort : ");
				PrintArr(arr, count, isNum);
			}
			factor *= 10;				// 그 다음 자리수로 간다.
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

		for (b = 0; b < 27; b++) qu_init(&queues[b], MAX_ARR, isNum);	// 큐들의 초기화

		for (d = 0; d < digits; d++) {
			unsigned char idx;
			for (i = 0; i < count; i++) {				// 데이터들을 자리수에 따라 큐에 입력
				idx = ARR_STR(arr)[i][j] - 'a' + 1;
				if (idx < 0) idx = 0;
				qu_push(&queues[idx], ARR_STR(arr)[i], isNum);
			}
			if (isAscending) {
				for (b = 0, i = 0; b < 27; b++)			// 버켓에서 꺼내어 list로 합친다.
					while (!((&queues[b])->rear == (&queues[b])->front)) {
						strcpy(ARR_STR(arr)[i++], qu_pop(&queues[b], isNum));
					}
			}
			else {
				for (b = 26, i = 0; b >= 0; b--)			// 버켓에서 꺼내어 list로 합친다.
					while (!((&queues[b])->rear == (&queues[b])->front)) {
						strcpy(ARR_STR(arr)[i++], qu_pop(&queues[b], isNum));
					}
			}

			if (doPrint) {
				printf("RadixSort : ");
				PrintArr(arr, count, isNum);
			}
			j--;				// 그 다음 자리수로 간다.
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
	printf("배열 생성 소요 시간 : %d(ms)\n", end - start);
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

	printf("배열 생성 중...\n");
	CreateRandArr(arr, num);
	printf("배열 생성 완료!!!\n");

	printf("정렬 중...\n");

	for (i = 0; i < FUNC_NUM; i++) {
		gap[i] = FuctionTimer(arr, num, TRUE, TRUE, FALSE, fp[i]);
		printf("%.3lf%% 진행중\n", (double)i / FUNC_NUM * 100);
	}
	printf("정렬 완료!!!\n");

	//system("cls");
	printf("--------------------------------------------\n");
	printf("정렬 실행 시간 비교\n");
	printf("%d개를 실행한 결과\n", BILLION);
	printf("Select Sort : %d(ms)\n", gap[0]);
	printf("Insert Sort : %d(ms)\n", gap[1]);
	printf("Bubble Sort : %d(ms)\n", gap[2]);
	printf("Quick Sort  : %d(ms)\n", gap[3]);
	printf("Shell Sort  : %d(ms)\n", gap[4]);
//	printf("Merge Sort  : %.3f\n", gap[3]);
//	printf("Heap Sort   : %.3f\n", gap[4]);
//	printf("Radix Sort  : %.3f\n", gap[5]);
	printf("--------------------------------------------\n");
	printf("완료되었습니다!!!\n");
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
		//문자열 혹은 숫자 처리
		system("cls");
		printf("------------------------\n");
		printf("데이터 값\n");
		printf("숫자   : 1\n");
		printf("문자열 : 2\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();
		if (cmd == '1')
			isNum = TRUE;
		else if (cmd == '2')
			isNum = FALSE;
		myArr = InitArr(isNum);

		//데이터 파일 처리
		system("cls");
		printf("------------------------\n");
		printf("입력 방식\n");
		printf("표준 입력 : 1\n");
		printf("파일      : 2\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();

		if (cmd == '1') {
			isSTI = TRUE;
		}
		else if (cmd == '2') {
			isSTI = FALSE;
			printf("데이터 파일 이름 : ");
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

		//오름차순, 내림차순 선택
		system("cls");
		printf("------------------------\n");
		printf("정렬 방식\n");
		printf("오름 차순 : 1\n");
		printf("내림 차순 : 2\n");
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

		//정렬 선택
		printf("------------------------\n");
		printf("사용할 정렬\n");
		printf("선택 정렬 : s\n");
		printf("삽입 정렬 : i\n");
		printf("버블 정렬 : b\n");
		printf("합병 정렬 : m\n");
		printf("히프 정렬 : h\n");
		printf("기수 정렬 : r\n");
		printf("퀵 정렬   : q\n");
		printf("쉘 정렬   : l\n");
		printf("정렬시간 비교 : t\n");
		printf("프로그램 종료 : x\n");
		printf("------------------------\n");
		printf(">> ");
		rewind(stdin);
		cmd = getchar();

		if (cmd == 't') {
			CompareSortingTime();
			continue;
		}

		//표준 입력(데이터 파일이 연결되어 있을 경우 이 과정 생략)
		if (isSTI && cmd != 'x') {
			char myStr[MAX_STR];
			count = 0;
			printf("------------------------------\n");
			printf("최대 50개까지 등록 가능합니다.\n");
			printf("입력을 종료 시 =를 입력하세요.\n");
			rewind(stdin);
			if (isNum) {
				unsigned char num;
				for (i = 0; i < MAX_ARR; i++) {
					printf("숫자 입력 (%d/50) : ", count);
					gets_s(myStr, sizeof(myStr));
					if (strcmp(myStr, "=") == 0) break;
					num = atoi(myStr);
					ARR_INT(myArr)[i] = num;
					count++;
				}
			}
			else {
				for (i = 0; i < MAX_ARR; i++) {
					printf("문자열 입력 (%d/50) : ", count);
					gets_s(myStr, sizeof(myStr));
					if (strcmp(myStr,"=") == 0) break;
					memset(ARR_STR(myArr)[i], 0, sizeof(myStr));
					strcpy(ARR_STR(myArr)[i], myStr);
					count++;
				}
			}
			printf("------------------------------\n");
		}

		//함수 실행
		switch (cmd) {
		case 's':
			SelectSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'i':
			InsertSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'b':
			BubbleSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'm':
			MergeSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'h':
			HeapSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'r':
			RadixSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'q':
			QuickSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
			getchar();
			break;
		case 'l':
			ShellSort(myArr, count, isAscending, isNum, TRUE);
			rewind(stdin);
			printf("\n***정렬이 완료되었습니다.***\n");
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
