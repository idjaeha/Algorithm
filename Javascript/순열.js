/*
순열
배열 arr이 주어졌을때 r개를 뽑아 나올 수 있는 경우의 수를 모두 배열로 반환하시오.
(단, arr.length >= r > 0이고 arr의 원소는 중복되지 않습니다.)
*/

const permutation = (src, r, temp, result) => {
  if (r === 0) {
    result.push(temp);
    return;
  }

  src.forEach((elem, idx) => {
    permutation(
      [...src.slice(0, idx), ...src.slice(idx + 1)],
      r - 1,
      [...temp, elem],
      result
    );
  });
};

const solution = (arr, r) => {
  const answer = [];
  permutation(arr, r, [], answer);
  console.log(answer);
  return answer;
};
