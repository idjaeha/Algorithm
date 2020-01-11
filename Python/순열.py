# 내부의 이중 for문이 돌 때마다 배열이 반환되는 함수
# soon 이라는 함수는 순열을 반환하는 함수이다.
# 배열에서 한 가지 값을 선택하고 그 값을 제외한 나머지 배열로 순열을 만드는 함수이다.
# 선택된 한 가지 값은 뒤에 나올 순열의 가지 수 만큼 반복되어야 한다.


def soon(arr):
    if len(arr) == 1:
        return [arr[0]]
    result = []

    for idx in range(len(arr)):
        picknum = arr[idx]
        next_arr = arr[:idx] + arr[idx+1:]
        for new_arr in soon(next_arr):
            if type(new_arr) == list:
                tmp = [picknum] + new_arr
            else:
                tmp = [picknum, new_arr]
            result.append(tmp)

    return result


print(soon(list(range(4))))

# tmp.append([0] + soon([1, 2]))         tmp = []
# tmp.append([0] + )

# soon([1, 2])
