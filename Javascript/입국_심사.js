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

/*
 내림차순으로 정렬한 list의 key 미만의 수가 처음으로 나오는 위치를 반환한다.
*/
const upperBound = (list, start, end, key) => {
  let mid;
  let result = list.length;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    if (list[mid] === undefined || list[mid][1] >= key) {
      start = mid + 1;
      continue;
    }
    result = Math.min(result, mid);
    end = mid - 1;
  }

  return result;
};

const solution = (M, waitlist) => {
  let answer = 0;
  waitlist.sort((a, b) => b[1] - a[1]);

  while (M > 0) {
    const cur = waitlist.pop();
    answer = cur[1];
    cur[1] += cur[0];
    const idx = upperBound(waitlist, 0, waitlist.length - 1, cur[1]);
    waitlist.splice(idx, 0, cur);
    M--;
  }

  console.log(answer);
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
    waitlist.map((x) => [Number.parseInt(x, 10), Number.parseInt(x, 10)])
  );
};

read();
