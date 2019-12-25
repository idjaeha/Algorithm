# 적은 데이터일 경우, 미리 계산해놓고 하는 방법에 대해 고려하자

result = [0 for _ in range(15 * 14)]
for idx in range(14):
    result[idx] = idx + 1

for k in range(14):
    for n in range(14):
        if n == 0:
            result[(k + 1) * 14 + n] = 1
            continue
        result[(k + 1) * 14 + n] = result[(k + 1) * 14 + n - 1] + result[k * 14 + n]

count = int(input())
for _ in range(count):
    k = int(input())
    n = int(input())
    print(result[k * 14 + n-1])