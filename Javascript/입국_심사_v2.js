/*
	1. [[심사에 걸리는 시간, 해당 심사를 했을 때 끝나는 시간], ...] 으로 배열을 생성한다.
	2. 해당 심사를 했을 때 끝나는 시간을 기준으로 정렬한다.
	3. 사람 수가 0이 될 때까지 반복한다.
    3-1. 첫번째 원소의 해당 심사를 했을 때 끝나는 시간을 answer에 저장한다.
    3-2. 첫번째 원소를 추출하여, 해당 심사를 했을 때 끝나는 시간 += 심사에 걸리는 시간을 진행한다.
		3-3. 변경된 값을 적절한 위치에 놓는다. (upperBound 사용)
		3-4. 사람 수를 -1 한다.
	4. answer를 반환한다.
*/
const solution = (M, waitlist) => {
  waitlist.sort((a, b) => b - a);
  let result = BigInt(waitlist[0] * M);
  let [start, end] = [0n, BigInt(result)];
  let mid;

  while (start < end) {
    mid = BigInt(start + end) / 2n;
    const sum = waitlist.reduce((prev, cur) => prev + mid / BigInt(cur), 0n);
    if (sum < M) {
      start = mid + 1n;
    } else {
      result = mid;
      end = mid;
    }
  }

  console.log(Number(result));
};

const read = () => {
  let input = require("fs")
    .readFileSync("./input.txt")
    .toString()
    .trim()
    .split("\n");
  const [NM, ...waitlist] = input;
  const M = Number.parseInt(NM.split(" ").pop(), 10);

  solution(
    M,
    waitlist.map((x) => Number.parseInt(x, 10))
  );
};

read();
