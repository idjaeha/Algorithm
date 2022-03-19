/*
https://programmers.co.kr/learn/courses/30/lessons/92342?language=javascript
2022 KAKAO BLIND RECRUITMENT
양궁 대회

최악의 경우에도 경우의 수가 적고, 제한시간 또한 10초로 넉넉하게 주었기 때문에 완전탐색을 진행해보자.

- 탐색 조건
1. 어피치의 화살이 있는 경우, 어피치의 화살 개수 + 1을 진행해본다. ( 그 이상은 의미가 없다... )
2. 어피치의 화살이 없는 경우, 1개를 넣어본다. ( 마찬가지로 일반적인 경우에는 1 이상은 의미가 없다. )

- 반환
1. 동률일 경우 가장 낮은 점수를 더 많이 맞힌 경우를 반환해야한다.
2. 가장 낮은 점수의 개수마저 동률일 경우 그 다음 개수를 본다.

- 풀이 순서
1. 탐색 조건에 따라 탐색하여 가장 높은 점수를 찾아낸다.
2. 가장 낮은 점수의 배열일 경우 저장한다.
3. 더 높은 점수를 찾아낸다면 2번에서 저장한 배열을 초기화하고 저장한다.
4. 같은 점수일 경우 해당 배열 또한 저장해놓는다.

- 가장 높은 점수를 찾아내는 방법 (중복 순열)
아래의 조건에 맞는 모든 경우를 찾아 비교해본다.
1. 가능한 어피치의 화살 개수 + 1, 아예 안넣는 경우도 포함.
2. 남은 화살 개수로 어피치의 화살이 없는 경우를 채움.
*/

// info에서 n개를 뽑아 answers에 저장하는 함수
const getScores = (n, info, answers, lionScores, maxGap, apeachScores) => {
  // 탈출 조건
  if (n === 0 || info.length === 0) {
    for (let _ = lionScores.length; _ < 11; _++) lionScores.push(0);
    if (info.length === 0) {
      lionScores[lionScores.length - 1] += n;
    }
    const gap = lionScores.reduce((prev, cur, idx) => {
      // 라이온이 점수를 얻는 경우
      if (cur > apeachScores[idx]) return prev + 10 - idx;
      // 어피치가 점수를 얻는 경우
      else if (apeachScores[idx] > 0) return prev - (10 - idx);
      // 둘다 0개라서 점수를 못 얻는 경우
      else return prev;
    }, 0);
    if (gap >= maxGap[0] && gap !== 0) {
      if (gap !== maxGap[0]) answers.length = 0;
      maxGap[0] = gap;
      if (answers.includes(lionScores.join("")) === false)
        answers.push(lionScores.join(""));
    }
    return;
  }

  // 본 로직
  info.forEach((elem, idx) => {
    // 남아있는 n이 elem보다 크면 elem + 1을 선택한다.
    if (n > elem && elem > 0) {
      getScores(
        n - (elem + 1),
        [...info.slice(idx + 1)],
        answers,
        [...lionScores, elem + 1],
        maxGap,
        apeachScores
      );
    }
    // 0을 만났을 경우에는 1을 선택한다.
    if (elem === 0) {
      getScores(
        n - 1,
        [...info.slice(idx + 1)],
        answers,
        [...lionScores, 1],
        maxGap,
        apeachScores
      );
    }
    // 아무것도 선택하지 않는 경우에는 0을 선택한다.
    getScores(
      n,
      [...info.slice(idx + 1)],
      answers,
      [...lionScores, 0],
      maxGap,
      apeachScores
    );
  });
};

function solution(n, info) {
  let maxGap = [0];
  let answers = [];

  getScores(n, info, answers, [], maxGap, info);
  answers = answers.map((answer) => answer.split("").map((x) => +x));
  if (answers.length === 0) return [-1];
  else if (answers.length === 1) return answers[0];
  else {
    const nums = answers.map((answer) =>
      answer.reduce((prev, cur, idx) => prev + cur * 2 ** idx, 0)
    );
    const max = Math.max(...nums);
    const idx = nums.indexOf(max);
    return answers[idx];
  }
}

// 예제 코드
console.log(solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]));
console.log(solution(1, [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]));
console.log(solution(9, [0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1]));
console.log(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3]));
console.log(solution(10, [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]));
console.log(solution(2, [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]));
