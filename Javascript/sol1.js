/*
0. n은 자연수 이므로 n > 0
1. 숫자를 저장한다. (number)
2. 숫자를 10으로 나눈 몫을 저장한다. (quota)
3. 숫자를 10으로 나눈 나머지를 저장한다. (remain)
4. 숫자를 remain로 나눈 나머지를 구한다.
    1. 이때 remain가 0이라면 구하지 않는다.
5. 숫자가 나누어 떨어졌다면 answer에 저장한다.
6. answer의 중복을 제거하여 길이를 반환한다.
*/

function solution(n) {
  const answer = new Set();
  const number = n;
  let quota = n;
  let remain = 0;

  while (quota > 0) {
    remain = quota % 10;
    if (remain !== 0 && number % remain === 0) answer.add(remain);
    quota = Math.floor(quota / 10);
  }

  return answer.size;
}

console.log(solution(1234));
