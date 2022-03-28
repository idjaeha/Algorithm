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

## 탐색 탈출 조건 (백트래킹 조건)
1. 현재 노드가 undefined인 경우
2. 늑대의 개수가 0보다 크고, 양의 개수 <= 늑대의 개수인 경우

## 문제 흐름
1. 입력을 토대로 이진트리를 생성한다.
  1-1. info를 통해 배열을 만든다.
  1-2. edges를 통해 left, right 값을 주입한다.
2. dfs를 통해 모든 경로를 탐색한다.
  2-1. 노드의 종류에 따라 양 또는 늑대의 개수를 늘려준다.
  2-2. 탐색 탈출 조건에 해당하는지 판별한다.
3. 반환.


## 위에 풀이는 오답, 간과한 사실
1. 한번 들렀던 노드여도 다시 들러볼 수 있다.

*/

const SHEEP = 0;
const WOLF = 1;

const LEFT = 0;
const RIGHT = 1;

const createNode = (type) => ({
  type,
  children: [],
});

const max = (a, b) => {
  if (a[SHEEP] > b[SHEEP]) return a;
  else if (a[SHEEP] < b[SHEEP]) return b;
  else if (a[WOLF] > b[WOLF]) return b;
  else return a;
};

// 양의 최대 개수를 구해주는 함수
const getMaxCount = (tree, curNode, count) => {
  if (curNode === undefined) return [...count];
  else if (count[WOLF] !== 0 && count[WOLF] >= count[SHEEP]) return [0, 0];

  count[curNode.type]++;
  console.log(count);
  count = max(
    count,
    getMaxCount(tree, tree[curNode.children[LEFT]], [...count])
  );
  return max(
    count,
    getMaxCount(tree, tree[curNode.children[RIGHT]], [...count])
  );
};

function wrongSolution(info, edges) {
  const tree = info.map((type) => createNode(type));
  edges.forEach(([x, y]) => {
    tree[x].children.push(y);
  });
  return getMaxCount(tree, tree[0], [0, 0])[SHEEP];
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
