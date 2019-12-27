# 값이 1일때 소수이다.
prime_list = [1 for _ in range(1000001)]
prime_list[0], prime_list[1] = 0, 0

for idx in range(2, 1000001):
    for num in range(idx + idx, 1000001, idx):
        prime_list[num] = 0

M, N = list(map(int, input().split()))
for num in range(M, N+1):
    if prime_list[num]:
        print(num)
