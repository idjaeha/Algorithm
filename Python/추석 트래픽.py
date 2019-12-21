def solution(lines):
    answer = 0
    result = {}
    # 모든 lines를 순회한다.
    # 각 값마다 완료 시간에 처리 시간을 뺀 시간을 구하여 해당하는 시간에 +1을 해준다.
    # 예) 58.120 1.01s -> 57.110 -> 58, 57 구간에 + 1을 해준다.
    # 이것을 저장하기 위해 hash를 사용한다.
    # 이유는 단순히 배열을 사용하기에는 너무 많은 공간이 사용되기 때문이다.
    # 더할때마다 최대값을 구하여 마지막에 반환한다.
    
    # 계산할 수 있도록 값을 변경한다.
    data_times = list(map(convertTime, lines))
    convertSecond = lambda x : int(float(x.split()[2][:-1]) * 1000)
    processing_times = list(map(convertSecond, lines))
    
    # 아래 과정을 모든 처리에 대하여 반복한다.
    # data_time 과 processing_time의 차를 이용하여 start_time과 finish_time을 int 형태로 구한다.
    # 그리고 그 차이만큼 반복하여 해쉬 값에 저장한다.
    # 내가 처음에 틀린 이유는 구간의 시작과 끝이 딱 떨어지는 구간,
    # 예를 들어 1초 ~ 2초와 같이 생각하여 풀었기 때문이다.
    # 두번째로 내가 틀린 이유는 구간을 생각하여 푼 것이 아닌 0.001초 마다 구간을 설정하여 생각했기 때문이다.
    # 세번째로 틀린 이유는 1초 구간을 설정할 때 시작 구간과 끝 구간이 포함되는 사실을 고려하지 않았기 때문이다.
    for idx in range(len(data_times)):
        start_time = data_times[idx] - processing_times[idx] + 1
        finish_time = data_times[idx]
        
        for time in range(start_time, finish_time + 1000):
            if time < 0:
                continue
            
            try:
                result[time] += 1
            except:
                result[time] = 1
            
            answer = max(answer, result[time])
    return answer

def convertTime(line):
    time = line.split()[1].split(':')
    
    return int((float(time[0]) * 60 * 60 + float(time[1]) * 60 + float(time[2])) * 1000 )