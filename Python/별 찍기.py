# 9개의 부분 중 가운데 부분을 삭제하는 함수
#
num = int(input())

star_list = ['*' for _ in range(num * num)]


def paint_star(star_list, num, size, start_idx):
    if size == 1:
        return
    erase_star(star_list, num, size, start_idx)
    for idx in range(9):
        if not idx == 4:
            row = (idx // 3) * (size // 3) * num
            col = (idx % 3) * (size // 3)
            paint_star(star_list, num, size // 3, start_idx + row + col)


def erase_star(star_list, num, size, idx):
    for row in range(size // 3 * num,  2 * (size // 3) * num, num):
        for col in range(size // 3, 2 * (size // 3)):
            star_list[idx + row + col] = ' '


paint_star(star_list, num, num, 0)

for row in range(num):
    for col in range(num):
        print(star_list[row * num + col], end="")
    print()
