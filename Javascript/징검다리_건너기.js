/*

	1. 연속된 길이의 합이 길면 midCnt = minCnt + 1
	2. 연속된 길이의 합이 짧으면 midCnt = maxCnt
	3. midCnt = (minCnt + maxCnt) / 2

*/

function solution(stones, maxMoveLen) {
  let minCnt = 200000001; // 건널 수 있는 최소 값
  let maxCnt = 0; // 건널 수 있는 최대 값
  let midCnt; // 건널 수 있는 친구들을 찾기 위한 값

  stones.forEach((x) => {
    if (x < minCnt) minCnt = x;
    if (x > maxCnt) maxCnt = x;
  });

  while (minCnt < maxCnt) {
    midCnt = Math.ceil((minCnt + maxCnt) / 2);

    let maxBrokenLen = 0;
    let brokenLen = 0;

    for (const stone of stones) {
      if (stone < midCnt) {
        brokenLen++;
        maxBrokenLen = Math.max(brokenLen, maxBrokenLen);
        if (maxBrokenLen === maxMoveLen) break;
      } else {
        brokenLen = 0;
      }
    }

    if (maxBrokenLen >= maxMoveLen) {
      // maxMoveLen 보다 maxLength가 크면 건널 수 없음을 의미함.
      maxCnt = midCnt - 1;
    } // k보다 maxLength가 작거나 같으면 건널 수 있음을 의미함.
    else {
      minCnt = midCnt;
    }
  }
  return minCnt;
}
