/*

1. 연속된 길이의 합이 길면 mid = start + 1
2. 연속된 길이의 합이 짧으면 mid = end
3. mid = (start + end) / 2
4. 

*/

function solution(stones, k) {
  let start = 200000001; // 건널 수 있는 최소 값
  let end = 0; // 건널 수 있는 최대 값
  let mid; // 건널 수 있는 친구들을 찾기 위한 값

  stones.forEach((x) => {
    if (x < start) start = x;
    if (x > end) end = x;
  });

  while (start < end) {
    mid = Math.ceil((start + end) / 2);

    let maxLength = 0;
    let curLength = 0;

    for (let idx = 0; idx < stones.length; idx++) {
      if (stones[idx] < mid) {
        curLength++;
        maxLength = Math.max(curLength, maxLength);
        if (maxLength === k) break;
      } else {
        curLength = 0;
      }
    }

    if (maxLength >= k) {
      // k 보다 maxLength가 크면 건널 수 없음을 의미함.
      end = mid - 1;
    } // k보다 maxLength가 작거나 같으면 건널 수 있음을 의미함.
    else {
      start = mid;
    }
  }
  return start;
}
