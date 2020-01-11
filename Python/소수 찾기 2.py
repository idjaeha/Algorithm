# 완전 탐색법
# 미리 구해놓는 방식으로 한다.
# 소수면 1 아니면 0을 출력한다.
prime_list = [1 for _ in range(10001)]
prime_list[0] = 0
prime_list[1] = 0
for num in range(2, 10001):
    for idx in range(num + num, 10001, num):
        prime_list[idx] = 0

M = int(input())
N = int(input())

answer = []
# M과 N 사이의 반복문을 실행시킨다.
# 만약 num가 소수일 경우 결과 값에 저장한다.
# 가장 작은 수(배열의 첫번째) 출력한다.
# 배열이 비어있을 경우 -1을 출력한다.
for num in range(M, N+1):
    if prime_list[num]:
        answer.append(num)

if len(answer) == 0:
    print(-1)
else:
    print(sum(answer))
    print(answer[0])
