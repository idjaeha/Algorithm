"""
문제 내용

문제
우리는 사람의 덩치를 키와 몸무게, 이 두 개의 값으로 표현하여 그 등수를 매겨보려고 한다.
어떤 사람의 몸무게가 x kg이고 키가 y cm라면 이 사람의 덩치는 (x,y)로 표시된다.
두 사람 A 와 B의 덩치가 각각 (x,y), (p,q)라고 할 때 x>p 그리고 y>q 이라면 우리는 A의 덩치가 B의 덩치보다 "더 크다"고 말한다. 예를 들어 어떤 A, B 두 사람의 덩치가 각각 (56,177), (45,165) 라고 한다면 A의 덩치가 B보다 큰 셈이 된다.
그런데 서로 다른 덩치끼리 크기를 정할 수 없는 경우도 있다.
예를 들어 두 사람 C와 D의 덩치가 각각 (45, 181), (55,173)이라면 몸무게는 D가 C보다 더 무겁고, 키는 C가 더 크므로, "덩치"로만 볼 때 C와 D는 누구도 상대방보다 더 크다고 말할 수 없다.

N명의 집단에서 각 사람의 덩치 등수는 자신보다 더 "큰 덩치"의 사람의 수로 정해진다.
만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다.
이렇게 등수를 결정하면 같은 덩치 등수를 가진 사람은 여러 명도 가능하다.
아래는 5명으로 이루어진 집단에서 각 사람의 덩치와 그 등수가 표시된 표이다.

이름	<몸무게, 키>	덩치 등수
A	    <55, 185>       	2
B	    <58, 183>	        2
C	    <88, 186>	        1
D	    <60, 175>	        2
E	    <46, 155>	        5

위 표에서 C보다 더 큰 덩치의 사람이 없으므로 C는 1등이 된다.
그리고 A, B, D 각각의 덩치보다 큰 사람은 C뿐이므로 이들은 모두 2등이 된다.
그리고 E보다 큰 덩치는 A, B, C, D 이렇게 4명이므로 E의 덩치는 5등이 된다.
위 경우에 3등과 4등은 존재하지 않는다.
여러분은 학생 N명의 몸무게와 키가 담긴 입력을 읽어서 각 사람의 덩치 등수를 계산하여 출력해야 한다.

"""


def solution():
    # 1. 숫자를 입력받아 리스트를 생성 후 저장한다. (예 : [[100, 50], [200, 40], ...])
    # 2. 처음 값부터 비교하여 자신보다 높은 사람이 몇명 있는지 찾는다.
    # 3. 자신보다 덩치가 큰 사람의 숫자 + 1 이 자신의 랭킹이 된다.

    num = int(input())
    body_list = []
    result = []
    for _ in range(num):
        body_list.append(list(map(int, input().split())))

    for value in body_list:
        result.append(compareValues(body_list, value))

    print(" ".join(map(str, result)))


def compareValues(body_list, value):
    rank = 0
    for body_value in body_list:
        if body_value[0] > value[0] and body_value[1] > value[1]:
            rank += 1

    return rank + 1


def main():
    solution()


if __name__ == "__main__":
    main()


"""
예제 입력 : 
5
55 185
58 183
88 186
60 175
46 155

예제 출력 : 
2 2 1 2 5
"""
