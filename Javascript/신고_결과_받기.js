/*
https://programmers.co.kr/learn/courses/30/lessons/92334?language=javascript
2022 KAKAO BLIND RECRUITMENT 신고 결과 받기

문제
- 중복된 신고를 어떻게 처리할 것인가?

흐름
1. 유저별로 해당 유저를 신고한 유저들을 알아낸다.
2. 그 신고한 유저들이 k 이상일 경우 신고한 유저들의 메일 개수를 +1 한다.
3. 메일 받은 개수를 배열로 반환한다.

해결
- 중복된 신고를 처리하는 방법
1. 중복된 신고의 경우 문자열이 완벽하게 일치하기 때문에 js의 set을 이용하여 중복된 문자열을 제거해준다.
	-> 이 방법이 신고가 굉장히 많을 경우 런타임 에러가 발생했음. (이유는 아직 모르겠음...)
	그래서 신고된 유저의 배열에 신고한 유저의 이름이 존재하지 않을 때만 추가하도록 변경함. (33번째줄 참고)

- 유저별로 해당 유저를 신고한 유저들을 알아내는 방법
1. 각 유저별로 {"유저 이름" : ["신고한 유저"], ...} 형태로 Object를 생성한다. (ex: {"muzi": []})

- 메일 받은 개수를 저장하는 방법
1. {"유저 이름": n, ...} 형태의 Object를 생성하여 처리한다. (기본 값은 {"name1": 0, "name2": 0, ...})

*/

function solution(id_list, report, k) {
    const mail_count = id_list.reduce((prev, cur) => ({...prev, [cur]: 0}), {});
    const reported_list = id_list.reduce((prev, cur) => ({...prev, [cur]: []}), {});
    
    report.forEach((elem) => {
        const [reporter, reported] = elem.split(" ");
        if (reported_list[reported].includes(reporter) === false)
            reported_list[reported].push(reporter);
     });
    
    id_list.forEach((id) =>
    {
        if (reported_list[id].length >= k)
        {
            reported_list[id].forEach((reporter) => {
                mail_count[reporter]++;
            })
        }
    });
    
    return id_list.map((id) => mail_count[id]);
}
