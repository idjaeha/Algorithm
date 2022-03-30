/*
	문제 링크: https://www.acmicpc.net/problem/2206
	입력 : N개의 M줄에 숫자 맵. (1,1) (N,M)은 항상 0
	출력 : 최단거리를 출력, 불가능할 때는 -1
	(1, 1) 에서 (N, M)의 위치까지 이동. 시작하는 칸과 끝나는 칸도 포함해서 셈.
	벽을 한 개 까지 부수고 이동 하여도 된다.
	1. 제일처음 0,0 에서 시작
	2. 4방향을 순회 할때
		- map 범위를 벗어날때
		- 이미 방문한 경우가 있을때
		- 이미 벽을 부셨는데 또 벽일때
	3.벽일때와 벽이 아닐때의 경우
		벽을 부수는 경우에는 벽을 부순 visit으로 넘겨준다
	4.벽을 부시고 도착한경우와 벽을 부시지 않고 도착한 경우를 나누기 위해서 배열에서 최소값을 return.
	벽부순 visit 안부순 visit ....
	bfs 방문배열은 '모든경우'를 살펴보며 진행할때, 같은 행위를 두번 반복하면 비효율적이니 막기 위해 사용.
	-> 방문배열은 모든경우를 나타낼 수 있어야함.
	visited[y][x][벽을부순상태?]
	참고 링크
	https://www.acmicpc.net/board/view/67446
	https://www.acmicpc.net/board/view/79649
	https://www.acmicpc.net/board/view/27386
*/

const bfs = (map, N, M) => {
  N = parseInt(N);
  M = parseInt(M);
  const visited = Array.from(new Array(N), () => new Array());

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      visited[i][j] = new Array(2).fill(0);
    }
  }
  let dy = [0, 0, -1, 1];
  let dx = [1, -1, 0, 0];
  let queue = [];
  let num = 0;
  let answer = [];
  visited[0][0][0] = 1;

  queue.push({ y: 0, x: 0, isBroken: 0 });
  //	벽을 부신경우 1 / 안부신경우 0

  while (queue.length !== num) {
    const cur = queue[num];
    if (cur.y === N - 1 && cur.x === M - 1 && map[cur.y][cur.x] === 0) {
      answer.push(1);
      break;
    }
    for (let i = 0; i < 4; i++) {
      const nextY = cur.y + dy[i];
      const nextX = cur.x + dx[i];
      if (nextY === N - 1 && nextX == M - 1) {
        //탈출조건 해당 좌표에 도착 했을때
        answer.push(visited[cur.y][cur.x][cur.isBroken] + 1);
        continue;
      }
      if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M) continue;
      if (visited[nextY][nextX][cur.isBroken] > 0) continue;
      if (map[nextY][nextX] === 1 && cur.isBroken === 1) continue;
      if (map[nextY][nextX] === 1) {
        //벽일때
        queue.push({ y: nextY, x: nextX, isBroken: 1 });
        visited[nextY][nextX][1] = visited[cur.y][cur.x][cur.isBroken] + 1;
      } else if (map[nextY][nextX] === 0) {
        //벽이 아닐때
        queue.push({ y: nextY, x: nextX, isBroken: cur.isBroken });
        visited[nextY][nextX][cur.isBroken] =
          visited[cur.y][cur.x][cur.isBroken] + 1;
      }
    }
    num++;
  }
  console.log(visited);
  answer.length === 0 ? console.log("-1") : console.log(Math.min(...answer));
  return;
};

const solution = (N, M, input) => {
  const map = input.map((arr) =>
    arr.split("").map((x) => {
      return Number(x);
    })
  );
  bfs(map, N, M);
  // console.log(map);
};
const read = () => {
  let input = require("fs")
    .readFileSync("./input_10x5.txt")
    .toString()
    .trim()
    .split("\n");
  const [N, M] = input.shift().split(" ");
  solution(N, M, input);
};

read();
