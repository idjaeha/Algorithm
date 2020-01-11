# 완전 탐색법
# 값이 1일때 소수이다.

count = int(input())
nums = list(map(int, input().split()))
answer = [1 for _ in range(1001)]
answer[1] = 0
result = 0
for num in range(2, 1001):
    for idx in range(num + num, 1001, num):
        answer[idx] = 0

for num in nums:
    result += answer[num]

print(result)
