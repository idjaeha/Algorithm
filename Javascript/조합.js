/*
조합
배열 arr이 주어졌을때 r개를 뽑아 나올 수 있는 경우의 수를 모두 배열로 반환하시오.
이때 배열의 원소가 동일하다면 같은 배열로 간주한다.
(단, arr.length >= r > 0이고 arr의 원소는 중복되지 않습니다.)
*/

const combination = (src, r, temp, result) => {
  if (r === 0) {
    result.push(temp);
    return;
  }

  src.forEach((elem, idx) => {
    combination([...src.slice(idx + 1)], r - 1, [...temp, elem], result);
  });
};

const solution = (arr, r) => {
  const answer = [];
  combination(arr, r, [], answer);
  console.log(answer);
  return answer;
};

solution([1, 2, 3], 2);
