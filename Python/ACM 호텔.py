# 아이디어 정리하기
# 1번째 손님은 101, 2번쨰 손님은 201, 층수만 살펴보면 1, 2, 3, 4, 5, ... , H 이런 순서로 올라감을 알 수 있다.
# 이것은 N을 H로 나누어서 생기는 나머지로 계산이 가능하다.
# 하지만 첫번째에 해당하는 손님이 1번에 가게되므로 N - 1을 해주어 첫번째 손님이 0번으로 가게 만들어준다.
# 호수 역시 1부터 시작하므로 0부터 시작할 수 있게 N - 1을 해주어 계산한다.
# N은 1 이상이므로 간단하게 표현될 수 있다.
count = int(input())

for _ in range(count):
    H, W, N = list(map(int, input().split()))
    N -= 1
    floor = (N % H) + 1
    no = (N // H) + 1
    print(floor * 100 + no)
