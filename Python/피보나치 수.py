fibonaci_list = [0, 1] + [-1 for _ in range(19)]


def fibonaci(num):
    if fibonaci_list[num] != -1:
        return fibonaci_list[num]
    return fibonaci(num - 1) + fibonaci(num - 2)


n = int(input())
print(fibonaci(n))
