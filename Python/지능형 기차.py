answer = []
cur_h = 0
for _ in range(4):
    out_h, in_h = list(map(int, input().split()))
    cur_h += in_h - out_h
    answer.append(cur_h)

print(max(answer))
