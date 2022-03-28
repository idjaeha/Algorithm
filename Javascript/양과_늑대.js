/*
https://programmers.co.kr/learn/courses/30/lessons/92343
2022 KAKAO BLIND RECRUITMENT
양과 늑대

각 노드를 방문하면서 모을 수 있는 양은 최대 몇 마리인지 반환하는 문제
양을 모으는 조건 : 양의 개수 > 늑대의 개수

## 입력
이진트리 형태로 생성됨.
info : 0은 양, 1은 늑대 (노드의 개수와 동일, 2 <= n <= 17)
edge : [[부모 노드의 번호, 자식 노드의 번호], ... , ...] (info.length - 1)

-> 가능한 모든 경로를 탐색해서 최대 값을 구하는 문제.
-> dfs 혹은 bfs를 이용해서 완전 탐색. -> bfs를 한번 해볼까..? -> 잘모르겠다 일단 dfs
-> 잘못된 경로일 경우 다시 되돌아가야하므로 백트래킹을 해야함.

## 탐색 탈출 조건 (백트래킹 탈출 조건)
1. 양의 개수 <= 늑대의 개수인 경우

## 문제 풀이
1. 인자값을 토대로 트리를 생성한다.
2. 방문한 곳을 순회한다.
3. 방문한 노드의 자식 노드가 아직 방문하지 않은 곳이라면 방문한다.
  3-1. 이때 현재 양의 개수와 방문을 마치고 나온 뒤 양의 개수를 비교하여 더 큰 값을 저장한다.
4. 방문이 끝난다면 해당 노드를 빠져나온다. (방문 배열에서 해당 노드를 제거한다.)
*/

const SHEEP = 0;
const WOLF = 1;

// 방문한 곳과 현재 위치를 줬을 때, 방문한 곳을 토대로 탐색할 수 있는 모든 경로를 탐색하는 함수
const getMaxSheep = (sheep, wolf, tree, visit, curIdx) => {
  if (tree[curIdx].type === SHEEP) sheep++;
  else wolf++;

  if (wolf >= sheep) return 0; // 0을 리턴하면 최대 값을 비교하기 때문에 의미 없는 값이 됨.

  let maxSheep = sheep;
  visit.forEach((parentIdx) => {
    tree[parentIdx].children.forEach((childIdx) => {
      if (visit.includes(childIdx) === false) {
        visit.push(childIdx);
        maxSheep = Math.max(
          maxSheep,
          getMaxSheep(sheep, wolf, tree, visit, childIdx)
        );
        visit.pop();
      }
    });
  });

  return maxSheep;
};

const createNode = (type) => ({
  type,
  children: [],
});

function solution(info, edges) {
  const tree = info.map((type) => createNode(type));
  edges.forEach(([x, y]) => {
    tree[x].children.push(y);
  });
  return getMaxSheep(0, 0, tree, [0], 0);
}

console.log(
  solution(
    [0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1],
    [
      [0, 1],
      [1, 2],
      [1, 4],
      [0, 8],
      [8, 7],
      [9, 10],
      [9, 11],
      [4, 3],
      [6, 5],
      [4, 6],
      [8, 9],
    ]
  )
);
