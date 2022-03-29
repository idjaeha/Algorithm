/*
https://www.acmicpc.net/problem/2206
벽 부수고 이동하기

(1, 1)에서 (N, M)까지 가는데에 필요한 최소 비용을 출력하는 문제.
이때 필요하다면 벽을 한개 부술 수 있다.
1 <= N <= 1000, 1 <= M <= 1000

## 아이디어
맵에 해당 지점까지 가는데에 소모한 비용을 저장해두고 그 값보다 작다면 이동한다.

## 탈출 조건
- 비용이 최대값을 벗어났다면 탈출
- 벗어났다면 탈출
- 목표 지점에 도착했다면 탈출
- 벽이라면
	- 벽을 부술 수 있는 상태인지 확인한다.
	- 벽을 부술 수 있다면
		- 부숴본다.
	- 벽을 부술 수 없다면
		- 종료한다.
- 벽이 아니라면
	- 이미 들렀던 곳이라면
		- 이때까지 사용한 비용 >= 지점의 비용이면
			- 종료

## 풀이 방법
1. 탈출 조건을 확인한다.
2. 비용 + 1을 한다.
3. 현재 지점에 해당 비용을 넣는다.
4. 4방향으로 움직인다.
*/

const EMPTY = "0";
const WALL = "1";
const MAX_NUM = 1000 * 1000;

const getMin = (map, X, Y, value, row, col, canBreak) => {
  count.count++;
  let min = MAX_NUM;
  if (X >= col || Y >= row || X < 0 || Y < 0) return MAX_NUM; // 입력값의 최대를 반환하여 결과에 영향을 주지 않음.
  if (value >= row * col) return MAX_NUM;
  if (map[Y][X] === WALL) {
    if (canBreak === true) {
      map[Y][X] = EMPTY;
      const result = Math.min(min, getMin(map, X, Y, value, row, col, false));
      map[Y][X] = WALL;
      return result;
    } else {
      return MAX_NUM;
    }
  } else {
    if (
      map[Y][X] !== EMPTY && // 들렀던 곳
      map[Y][X] <= value
    )
      return MAX_NUM;
  }

  value++;
  map[Y][X] = value;
  if (X === col - 1 && Y === row - 1) {
    return value;
  }

  min = Math.min(min, getMin(map, X + 1, Y, value, row, col, canBreak));
  min = Math.min(min, getMin(map, X - 1, Y, value, row, col, canBreak));
  min = Math.min(min, getMin(map, X, Y + 1, value, row, col, canBreak));
  min = Math.min(min, getMin(map, X, Y - 1, value, row, col, canBreak));

  return Math.min(MAX_NUM, min);
};

const solution = () => {
  const [info, ...mapString] = require("fs")
    // .readFileSync("/dev/stdin")
    .readFileSync("./input.txt")
    .toString()
    .trim()
    .split("\n");
  const [row, col] = info.split(" ").map((x) => Number.parseInt(x, 10));
  const map = mapString.map((line) => [...line]);
  const result = getMin(map, 0, 0, 0, row, col, true);
  if (result === MAX_NUM) return -1;
  return result;
};

console.log(solution());
