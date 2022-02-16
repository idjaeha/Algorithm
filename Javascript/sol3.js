/*
1. 상하좌우로 움직여본다.
2. 목적지에 도착했다면 그때까지의 비용을 result에 저장한다.
3. 목적지에 도착하지 못했다면 종료시킨다. 목적지에 도착하지 못하는 조건은 다음과 같다.
    1. 접근할 수 없는 곳으로 접근하려는 경우
    2. 이미 탐색한 곳으로 이동한 경우
    3. 현재 value가 해당 위치의 최소 value보다 큰 경우
4. 구해진 값들의 최소값을 반환한다.
*/

const EMPTY = 0;
const STONE = 1;
const PLAYER = 2;
const EXIT = 3;
const CHECKED = 8;
const MAX_NUM = 10000;

function getValue(answer, board, pos, c, curValue, valueBoard) {
  if (pos.x === -1 || pos.x === board[0].length) return;
  if (pos.y === -1 || pos.y === board.length) return;
  if (board[pos.y][pos.x] >= CHECKED) return;
  if (curValue > valueBoard[pos.y][pos.x]) return;

  if (board[pos.y][pos.x] === EXIT) {
    if (curValue < answer.value) answer.value = curValue;
    return;
  }

  curValue += board[pos.y][pos.x] === STONE ? c : 0;
  board[pos.y][pos.x] += CHECKED;
  if (curValue < valueBoard[pos.y][pos.x]) {
    valueBoard[pos.y][pos.x] = curValue;
  }
  getValue(
    answer,
    board,
    { x: pos.x, y: pos.y + 1 },
    c,
    curValue + 1,
    valueBoard
  );
  getValue(
    answer,
    board,
    { x: pos.x + 1, y: pos.y },
    c,
    curValue + 1,
    valueBoard
  );
  getValue(
    answer,
    board,
    { x: pos.x, y: pos.y - 1 },
    c,
    curValue + 1,
    valueBoard
  );
  getValue(
    answer,
    board,
    { x: pos.x - 1, y: pos.y },
    c,
    curValue + 1,
    valueBoard
  );
  board[pos.y][pos.x] -= CHECKED;
}

function findPos(board, target) {
  for (let y = 0; y < board.length; y++) {
    for (let x = 0; x < board[0].length; x++) {
      if (board[y][x] === target) return { x, y };
    }
  }
}

function solution(board, c) {
  const valueBoard = Array.from({ length: board.length }, (_) =>
    Array.from({ length: board[0].length }, (_) => MAX_NUM)
  );
  const start = findPos(board, PLAYER);
  const answer = {
    value: MAX_NUM,
  };
  board[start.y][start.x] = EMPTY;
  getValue(answer, board, start, c, 0, valueBoard);
  console.log(valueBoard);
  return answer.value;
}

console.log(
  solution(
    [
      [0, 0, 0, 0, 2, 0, 0, 0, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 1, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 0, 0],
      [0, 0, 0, 0, 3, 0, 0, 0, 1, 0],
    ],
    1
  )
);

console.log(
  solution(
    [
      [0, 0, 0, 0, 2, 0, 0, 0, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 1, 0],
      [0, 0, 1, 1, 1, 1, 1, 0, 0, 0],
      [0, 0, 0, 0, 3, 0, 0, 0, 1, 0],
    ],
    2
  )
);

console.log(
  solution(
    [
      [1, 0, 0, 0, 2, 0, 0, 0, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 0, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 0, 1, 1, 1, 1, 1, 0, 1, 0],
      [1, 0, 1, 1, 1, 1, 1, 0, 0, 0],
      [1, 0, 0, 0, 3, 0, 0, 0, 1, 0],
    ],
    2
  )
);
