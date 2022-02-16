// 1. answers를 순회하며 idx로 맞춘 갯수를 측정한다.
// 2. Math.max를 통해 max 값을 알아낸다.
// 3. 해당 max값과 동일한 idx를 반환한다.

function solution(answers) {
  const first = [1, 2, 3, 4, 5];
  const second = [2, 1, 2, 2, 2, 3, 2, 4, 2, 5];
  const third = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
  const rightCounts = [0, 0, 0];

  answers.forEach((answer, idx) => {
    rightCounts[0] += answer === first[idx % first.length];
    rightCounts[1] += answer === second[idx % second.length];
    rightCounts[2] += answer === third[idx % third.length];
  });

  const maxCount = Math.max(...rightCounts);

  return rightCounts.reduce(
    (prev, cur, idx) => (cur === maxCount ? [...prev, idx + 1] : prev),
    []
  );
}

console.log(solution([1, 1, 1]));
