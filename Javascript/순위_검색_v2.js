const lowerBound = (list, start, end, key) => {
  let mid;
  let result = 100001;

  while (start <= end) {
    mid = Math.floor((start + end) / 2);
    if (list[mid] < key) {
      start = mid + 1;
      continue;
    }
    result = Math.min(result, mid);
    end = mid - 1;
  }

  return result;
};

const origin = [
  ["-", "java", "python", "cpp"],
  ["-", "backend", "frontend"],
  ["-", "junior", "senior"],
  ["-", "pizza", "chicken"],
];

const data = {};
for (let idx_1 = 0; idx_1 < 4; idx_1++)
  for (let idx_2 = 0; idx_2 < 3; idx_2++)
    for (let idx_3 = 0; idx_3 < 3; idx_3++)
      for (let idx_4 = 0; idx_4 < 3; idx_4++) {
        const key =
          origin[0][idx_1] +
          " and " +
          origin[1][idx_2] +
          " and " +
          origin[2][idx_3] +
          " and " +
          origin[3][idx_4];
        data[key] = [];
      }

const pushInfo = (info) => {
  const [lang, job, career, food, strScore] = info.split(" ");

  for (let idx_1 = 0; idx_1 < 2; idx_1++)
    for (let idx_2 = 0; idx_2 < 2; idx_2++)
      for (let idx_3 = 0; idx_3 < 2; idx_3++)
        for (let idx_4 = 0; idx_4 < 2; idx_4++) {
          const key =
            (idx_1 === 0 ? "-" : lang) +
            " and " +
            (idx_2 === 0 ? "-" : job) +
            " and " +
            (idx_3 === 0 ? "-" : career) +
            " and " +
            (idx_4 === 0 ? "-" : food);
          data[key].push(Number.parseInt(strScore, 10));
        }
};

function solution(info, query) {
  info.forEach(pushInfo);
  Object.keys(data).forEach((key) => data[key].sort((a, b) => a - b));

  return query.map((q) => {
    const parsed = q.split(" ");
    const score = Number.parseInt(parsed.pop(), 10);
    const key = parsed.join(" ");

    return data[key].length - lowerBound(data[key], 0, data[key].length, score);
  });
}
