def count_house(raw_list, checked_list, result_list):
    num = len(raw_list)
    for j in range(num):
        for i in range(num):
            if raw_list[j][i] == 1 and checked_list[j][i] == 0:
                idx = (i, j)
                result_list.append(checked_adj(raw_list, checked_list, idx))


def checked_adj(raw_list, checked_list, idx):
    stack = []
    visit = []
    stack.append(idx)
    while stack:
        node = stack.pop()
        if node not in visit:
            i, j = node
            visit.append(node)
            checked_list[j][i] = 1

            if j != 0 and raw_list[j - 1][i] == 1 and checked_list[j - 1][i] == 0:
                stack.append((i, j - 1))
            if j != len(raw_list) - 1 and raw_list[j + 1][i] == 1 and checked_list[j + 1][i] == 0:
                stack.append((i, j + 1))
            if i != 0 and raw_list[j][i - 1] == 1 and checked_list[j][i - 1] == 0:
                stack.append((i - 1, j))
            if i != len(raw_list) - 1 and raw_list[j][i + 1] == 1 and checked_list[j][i + 1] == 0:
                stack.append((i + 1, j))

    return visit


num = int(input())
raw_list = [[] for _ in range(num)]
checked_list = [[0 for _ in range(num)] for _ in range(num)]
result_list = []  # 결과 값을 저장하는 배열

for idx in range(num):
    raw_list[idx].extend(map(int, list(input())))

count_house(raw_list, checked_list, result_list)
result_list = sorted(result_list, key=lambda x: len(x))

print(len(result_list))
for result in result_list:
    print(len(result))
