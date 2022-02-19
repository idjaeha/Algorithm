/*
https://programmers.co.kr/learn/courses/30/lessons/42842?language=javascript

- 전체 가로 길이 >= 세로 길이 >= 3
- 갈색 타일의 개수 = 노란 타일의 가로 길이 * 2 + 노란 타일의 세로 길이 * 2 + 4
-> 노란 타일 개수의 약수를 통해 가능한 경우의 수를 구한 후 갈색 타일의 개수도 일치하는지 확인한다.

1. 1부터 노란 타일 개수의 제곱근만큼 반복한다.
    1. 개수 / n 을 통해 나누어 떨어지는 경우의 수를 찾는다.
    2. 나누어 떨어진 경우 갈색 타일의 개수와 일치하는지 확인한다.
*/

function solution(brown, yellow) {
  const answer = [0, 0];
  const sqrtYellow = Math.sqrt(yellow);

  for (let n = 1; n <= sqrtYellow; n++) {
    if (yellow % n === 0) {
      const col = yellow / n;
      const row = n;
      if (brown === (row + col) * 2 + 4) {
        answer[0] = col + 2;
        answer[1] = row + 2;
        break;
      }
    }
  }

  return answer;
}
