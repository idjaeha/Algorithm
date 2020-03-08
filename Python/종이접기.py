"""
문제 내용

직사각형 종이를 n번 접으려고 합니다. 이때, 항상 오른쪽 절반을 왼쪽으로 접어 나갑니다. 다음은 n = 2인 경우의 예시입니다.
먼저 오른쪽 절반을 왼쪽으로 접습니다.
다시 오른쪽 절반을 왼쪽으로 접습니다.
종이를 모두 접은 후에는 종이를 전부 펼칩니다. 종이를 펼칠 때는 종이를 접은 방법의 역순으로 펼쳐서 처음 놓여있던 때와 같은 상태가 되도록 합니다. 위와 같이 두 번 접은 후 종이를 펼치면 아래 그림과 같이 종이에 접은 흔적이 생기게 됩니다.
위 그림에서 ∨ 모양이 생긴 부분은 점선(0)으로, ∧ 모양이 생긴 부분은 실선(1)으로 표시했습니다.
종이를 접은 횟수 n이 매개변수로 주어질 때, 종이를 절반씩 n번 접은 후 모두 펼쳤을 때 생기는 접힌 부분의 모양을 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항
종이를 접는 횟수 n은 1 이상 20 이하의 자연수입니다.
종이를 접었다 편 후 생긴 굴곡이 ∨ 모양이면 0, ∧ 모양이면 1로 나타냅니다.
가장 왼쪽의 굴곡 모양부터 순서대로 배열에 담아 return 해주세요.
"""


def fold(start, end, mid, value_list):
    # 단위 면에서 가운데 선을 기준으로 접었을 때, 양 옆에 생기는 선을 그려주는 함수
    if start + 1 == mid or mid + 1 == end:
        return
    # print("start, end, mid = {0}, {1}, {2}3".format(start, end, mid))
    # print("end + mid // 2 = {0}".format((end + mid) // 2))
    value_list[(start + mid) // 2] = 0
    value_list[(end + mid) // 2] = 1
    fold(start, mid, (start+mid) // 2, value_list)
    fold(mid, end, (mid+end) // 2, value_list)


def solution():
    # 단위 면을 생각했을 때, 단위 면의 가운데 선을 기준으로 왼쪽 선은 0, 오른쪽 선은 1을 나타낸다.
    # start와 end를 설정해주기 위해 종이의 양 끝도 선으로 표기한다.

    num = int(input())
    value_list = [0 for x in range(2**num + 1)]
    mid = (2**num + 1) // 2
    value_list[mid] = 1
    fold(0, len(value_list) - 1, mid, value_list)
    result = value_list[1:-1]
    print(result)


def main():
    solution()


if __name__ == "__main__":
    main()


"""
예제 입력 : 
n	result
1	[0]
2	[0,0,1]
3	[0,0,1,0,0,1,1]

예제 출력 : 
입출력 예 #1
종이의 오른쪽 절반을 왼쪽으로 한번 접었다 펴면 아래 그림과 같이 굴곡이 생깁니다.

따라서 [0]을 return 하면 됩니다.

입출력 예 #2
문제의 예시와 같습니다.

입출력 예 #3
종이를 절반씩 세 번 접은 후 다시 펼치면 아래 그림과 같이 굴곡이 생깁니다.

따라서 [0,0,1,0,0,1,1]을 return 하면 됩니다.
"""
