/*
https://programmers.co.kr/learn/courses/30/lessons/92341
2022 KAKAO BLIND RECRUITMENT
주차 요금 계산

1. records를 분리 (ex : "05:34 5961 IN")
2. HH:MM을 분 단위로 변경 (ex : 01:01 -> 61)
3. 자동차 번호를 숫자로 변경.
4. map에 key: 번호, value: 총 주차시간을 저장할 예정.
5. 이때 입차인 경우에는 2번에서 구한 분 단위를 음수로 저장하고 출차인 경우에는 양수로 저장하여 둘을 합함.
	5-1. 이렇게 진행하면 같은 차량이 여러번 왔다갔다 했을 경우를 고려할 수 없음. 때문에 이후에 진행하는게 나을듯
6. 모든 records를 순회한 후에 배열의 개수가 홀수인 경우 23:59에 해당하는 분을 추가해줌.
7. map을 순회하면서 시간을 금액으로 변환. (6, 7번 과정을 같이 진행해도 괜찮을듯.)
8. 결과값을 정렬하여 반환.
*/

const toMin = (time) => {
  const [hour, min] = time.split(":");
  return Number.parseInt(hour, 10) * 60 + Number.parseInt(min, 10);
};

const solution = (fees, records) => {
  const [baseMin, baseWon, perMin, perWon] = fees;
  const feeMap = new Map();

  // feeMap에 record를 추가함.
  records.forEach((record) => {
    const [time, carNumberStr, flag] = record.split(" ");
    const carNumberInt = Number.parseInt(carNumberStr, 10);
    let carRecords = feeMap.get(carNumberInt);
    if (carRecords === undefined) {
      carRecords = [];
      feeMap.set(carNumberInt, carRecords);
    }
    carRecords.push(toMin(time) * (flag === "IN" ? -1 : 1));
  });

  const feeArray = [];
  // 요금 계산
  feeMap.forEach((carRecords, carNumber) => {
    // 입차하고 나가지 않은 경우
    if (carRecords.length % 2 === 1) carRecords.push(toMin("23:59"));
    const sum = carRecords.reduce((prev, cur) => prev + cur, 0);
    const addMin = sum - baseMin < 0 ? 0 : sum - baseMin;
    feeArray.push([carNumber, baseWon + Math.ceil(addMin / perMin) * perWon]);
  });

  feeArray.sort((a, b) => a[0] - b[0]);
  return feeArray.map((fee) => fee[1]);
};
