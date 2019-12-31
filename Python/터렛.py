import math

# 겹치는 곳이 없으면 0 으로 취급한다.

# 두 원이 떨어져있을 때 o
# 0
# 두 원 사이의 거리 dist, 원1 반지름 r1, 원2 반지름 r2
# r1 + r2 < dist

# 두 원이 외부에서 접해있을 때 o
# 1
# r1 + r2 = dist

# 두 원이 만났을 때
# 2
# r1 + r2 > dist

# 두 원이 내부에서 접해있을 때 o
# 1
# r2 - r1 = dist

# 원 안에 원이 있을 때  
# 0
# r2 - r1 > dist

# 두 원이 완전히 접할 때 o
# -1 ( 무한대 )
# r2 == r1


count = int(input())
for _ in range(count):
    x1, y1, r1, x2, y2, r2 = list(map(int, input().split()))
    dist = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    
    if r1 + r2 < dist: # 두 원이 떨어져 있을 때
        print(0)
    elif r1 + r2 == dist: # 두 원이 외부에서 접해 있을 때
        print(1)
    elif r1 + r2 > dist and r1 == r2 and dist == 0: # 두 원이 완전히 겹쳤을 때
        print(-1)
    elif r1 + r2 > dist and abs(r2 - r1) == dist: # 원 내부에서 접했을 때
        print(1)
    elif r1 + r2 > dist and abs(r2 - r1) > dist: # 원 안에서 아무것도 접하지 않을 때
        print(0)
    else: # 나머지 경우
        print(2)
        
            
                  
            



