const DEAD = 0;
const OLD = 2;

const solution = (N, usage, trees, targetYear, foodsInfo) => {
  let deadTrees;
  let parentTrees;
  let tempTrees;

  for (let curYear = 0; curYear < targetYear; ++curYear) {
    deadTrees = [];
    parentTrees = [];
    aliveTrees = [];
    trees.sort((a, b) => b[2] - a[2]);

    for (let idx = trees.length - 1; idx >= 0; --idx) {
      const tree = trees[idx];
      const [row, col, old] = tree;

      if (usage[row][col] >= old) {
        usage[row][col] -= tree[OLD];
        tree[OLD] += 1;
        if (tree[OLD] % 5 === 0) parentTrees.push(tree);
        aliveTrees.push(tree);
      } else {
        deadTrees.push(tree);
      }
    }

    deadTrees.forEach((tree) => {
      const [row, col, _] = tree;
      usage[row][col] += Math.floor(tree[OLD] / 2);
    });

    parentTrees.forEach(([row, col, _]) => {
      row !== 0 && col !== 0 && aliveTrees.push([row - 1, col - 1, 1]);
      row !== 0 && aliveTrees.push([row - 1, col, 1]);
      row !== 0 && col !== N - 1 && aliveTrees.push([row - 1, col + 1, 1]);
      row !== N - 1 && col !== 0 && aliveTrees.push([row + 1, col - 1, 1]);
      row !== N - 1 && aliveTrees.push([row + 1, col, 1]);
      row !== N - 1 && col !== N - 1 && aliveTrees.push([row + 1, col + 1, 1]);
      col !== 0 && aliveTrees.push([row, col - 1, 1]);
      col !== N - 1 && aliveTrees.push([row, col + 1, 1]);
    });

    for (let i = 0; i < N; ++i) {
      for (let j = 0; j < N; ++j) {
        usage[i][j] += foodsInfo[i][j];
      }
    }

    trees = aliveTrees;
  }

  console.log(trees.filter((tree) => tree[OLD] !== DEAD).length);
};

const read = () => {
  let input = require("fs")
    .readFileSync("./input copy.txt")
    .toString()
    .trim()
    .split("\n");
  const [NMK, ...list] = input;
  const [N, _, targetYear] = NMK.split(" ").map((x) => Number.parseInt(x, 10));

  const foodsInfo = list
    .slice(0, N)
    .map((line) => line.split(" ").map((num) => Number.parseInt(num, 10)));

  const usage = list.slice(0, N).map((line) => line.split(" ").map((_) => 5));

  const trees = list
    .slice(N)
    .map((line) => line.split(" ").map((num) => Number.parseInt(num, 10)));

  trees.forEach((tree) => {
    const [x, y, _] = tree;
    tree[0] = x - 1;
    tree[1] = y - 1;
  });

  solution(N, usage, trees, targetYear, foodsInfo);
};

const start = new Date();
read();
console.log(new Date() - start);
