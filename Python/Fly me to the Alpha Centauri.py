# 간격 >= 지금까지의 합x2 이고 (현재 진행 거리 + 1) <= 간격 - 지금까지의 합x2 -> 현재 진행 거리 + 1
# 간격 >= 지금까지의 합x2 이고 (현재 진행 거리 + 1) > 간격 - 지금까지의 합x2 -> 현재 진행 거리
# 간격 < 지금까지의 합x2 -> 현재 진행 거리 - 1

count = int(input())
for _ in range(count):
    start, end = list(map(int, input().split()))
    gap = end - start
    answer = 0
    cur_pos = 0
    add_pos = 0
    while cur_pos < gap:
        flag = gap - cur_pos * 2
        if flag >= 0:
            if flag >= add_pos + 1:
                add_pos += 1
            cur_pos += add_pos
            answer += 1
        else:
            if gap - cur_pos > add_pos*(add_pos-1) / 2:
                if gap - cur_pos - add_pos*(add_pos-1) / 2 == 1:
                    answer += add_pos
                else:
                    answer += add_pos
            else:
                answer += (add_pos - 1)
            break
        
    print(answer)