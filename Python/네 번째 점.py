# 값이 한 개인 값을 구한다.

x_list = []
y_list = []
xy = []
for _ in range(3):
    x, y = list(map(int, input().split()))
    x_list.append(x)
    y_list.append(y)

for tmp_x in x_list:
    if x_list.count(tmp_x) == 1:
        xy.append(tmp_x)
        break

for tmp_y in y_list:
    if y_list.count(tmp_y) == 1:
        xy.append(tmp_y)
        break

print(xy[0], xy[1])
