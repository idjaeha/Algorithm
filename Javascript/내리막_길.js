/*
	내리막 길 (1520)
	https://www.acmicpc.net/problem/1520

	왼쪽 위에서 시작하여 내리막길(현재 노드의 숫자보다 숫자 미만인 곳)로만 이동하여 오른쪽 아래에 도달하는 경로를 구하는 문제.
	-> 가능한 경로의 개수를 출력하는 문제

	1 <= M, N <= 500
	1 <= 노드 값 <= 10000

	재귀로 풀자
	# 함수
	- 목적지면 1을 반환하고 아니면 상하좌우중 이동 가능한 곳으로 이동하는 함수.

	# 함수 탈출 조건
	- 오른쪽 아래(N - 1, M - 1)에 도착했을 때, 1을 반환하며 탈출

	# 성능을 고려한다면?
	- 도착하면 이때까지의 경로의 visit을 전부 1로 변경한다.
	- visit이 1이라면 도달할 수 있는 경로라고 간주하고 1을 반환한다.
*/

const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];
let map;
let visit;
let row;
let col;

const move = (x, y) => {
  if (x === 0 && y === 0) {
    return 1;
  }
  if (visit[y][x] != -1) {
    return visit[y][x];
  }
  visit[y][x] = 0;
  for (let idx = 0; idx < 4; idx++) {
    const [nextX, nextY] = [x + dx[idx], y + dy[idx]];
    if (0 <= nextX && nextX < col && 0 <= nextY && nextY < row) {
      if (map[y][x] < map[nextY][nextX]) {
        visit[y][x] += move(nextX, nextY);
      }
    }
  }
  return visit[y][x];
};

const solution = () => {
  const [info, ...mapString] = require("fs")
    .readFileSync("/dev/stdin")
    // .readFileSync("./test.txt")
    .toString()
    .trim()
    .split("\n");
  [row, col] = info.split(" ").map((x) => Number.parseInt(x, 10));
  map = mapString.map((line) =>
    line.split(" ").map((x) => Number.parseInt(x, 10))
  );
  visit = map.map((line) => line.map((_) => -1));
  console.log(move(col - 1, row - 1));
};

solution();
