/*
1. s를 순회하면서 다음을 비교한다.
    0. cursor의 index가 마지막이라면 탈출한다.
    1. cursor의 index가 짝수일 경우 index + 1에 해당하는 값이 작거나 같은지 판단한다.
        1. 만약 작거나 같다면, -10001을 추가한다고 가정한다. 즉, answer + 1을 진행한다.
    2. cursor의 index가 홀수일 경우 index + 1에 해당하는 값이 크거나 같은지 판단한다.
        1. 만약 크거나 같다면, 10001을 추가한다고 가정한다. 즉, answer + 1을 진행한다.
    3. cursor를 다음 칸으로 이동시킨다.
*/

const MAX_NUM = 10001;
const MIN_NUM = -10001;

function solution(s) {
  let answer = 0;
  let idx = 0;

  while (idx + 1 < s.length) {
    if (idx % 2 === 0 && s[idx] >= s[idx + 1]) {
      s.splice(idx + 1, 0, MAX_NUM);
      answer++;
    } else if (idx % 2 === 1 && s[idx] <= s[idx + 1]) {
      s.splice(idx + 1, 0, MIN_NUM);
      answer++;
    }
    idx++;
  }

  return answer;
}

console.log(solution([1, 2, 3]));
console.log(solution([3, -1, 0, 4]));
