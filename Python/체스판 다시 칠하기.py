"""
문제 내용

지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다.
어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다.
지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다.
구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고,
변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다.
따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다.
하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다.
당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

출력
첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.
"""


def solution():
    # 1. 8x8 사이즈의 정사각형을 탐색한다.
    # 2. 해당 정사각형을 탐색하여 조건에 일치하는 갯수를 구한다.
    # 3. 최솟값을 구한다.
    row, col = map(int, input().split())
    raw_list = []
    min_value = 99999999999
    for _ in range(row):
        raw_list.append(list(input()))

    for start_y in range(row - 7):
        for start_x in range(col - 7):
            min_value = min(min_value, check_valid(raw_list, start_y, start_x))

    print(min_value)


def check_valid(raw_list, start_y, start_x):
    # start_x와 start_y 를 시작으로 8x8 크기의 정사각형을 탐색하여 몇 개를 고치면 될지 찾아낸다.
    # 첫 시작이 W인 경우와 B인 경우를 나누어서 계산하여 더 작은 값을 도출한다.

    FLAG = ('W', 'B')
    flag = 0
    valid = [0, 0]

    for row in range(start_y, start_y + 8):
        for col in range(start_x, start_x + 8):
            if raw_list[row][col] == FLAG[flag]:
                valid[0] += 1
            flag = (flag + 1) % 2
        flag = (flag + 1) % 2

    flag = 1
    for row in range(start_y, start_y + 8):
        for col in range(start_x, start_x + 8):
            if raw_list[row][col] == FLAG[flag]:
                valid[1] += 1
            flag = (flag + 1) % 2
        flag = (flag + 1) % 2
    return 64-max(valid)


def main():
    solution()


if __name__ == "__main__":
    main()


"""
예제 입력 :
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW

10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB

예제 출력 :
1

12
"""
