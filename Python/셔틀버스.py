def solution(n, t, m, timetable):
    answer = ''

    # 도착할 사람이 있는지 점검
    # 버스 출발
    # 제일 마지막에 도착하는 버스의 잔여석을 확인하자
    # 만약 자리가 남아있을 경우 마지막에 도착하는 버스와 동일한 시간을 출력한다.
    # 만약 버스 자리가 남아있지 않을 경우 탈 수 있는 사람 중 가장 느린 사람보다 1분 빨리 도착한다.
    # 비교하기 편하게 timetable을 비교 가능한 숫자로 변경하고 다시 문자열로 변경해서 출력한다.
    # 앞에서 손님이 얼마나 남을지 모르기 때문에 맨 앞 차량부터 비교해야한다.

    # 1. 문자열을 숫자로 변경한다.-> 01:30 -> 90
    # 2. 해당 배열을 오름차순으로 정렬한다.
    # 3. 버스 도착 시간에 맞춰 해당 시간보다 적은 손님들을 태운다.
    # 4. 만약 마지막 버스가 꽉찼다면 콘을 마지막 손님보다 1분 빨리 태운다.
    # 5. 만약 마지막 버스가 비어있다면 마지막 버스 시간에 콘을 태운다,
    # 6. 그 시간을 문자열로 변경하여 출력한다.

    start_time = 9 * 60
    def convert_int(x): return int(x[:2]) * 60 + int(x[3:])
    timetable_int = list(map(convert_int, timetable))
    timetable_int.sort()

    bus_flag = True  # 마지막에 버스 빈자리가 있다면 True, 없다면 False
    bus_guest_num = 0
    idx_guest = 0

    for time in range(n):
        arrive_time = start_time + time * t
        bus_guest_num = 0
        for _ in range(m):
            if idx_guest == len(timetable_int):
                break

            if timetable_int[idx_guest] <= arrive_time:
                if bus_guest_num < m:
                    idx_guest += 1
                    bus_guest_num += 1

    if bus_guest_num < m:
        answer = arrive_time
    else:
        answer = timetable_int[idx_guest - 1] - 1

    answer = "{:02}:{:02}".format(answer // 60, answer % 60)

    return answer
