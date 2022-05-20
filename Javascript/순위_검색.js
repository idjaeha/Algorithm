/*
1. info 파싱
2. query 파싱
3. query.map()을 이용하여 answer 구하기
*/

const parseInfo = (info) =>
  info.map((item) => {
    const temp = item.split(" ");
    temp[temp.length - 1] = Number.parseInt(temp[temp.length - 1], 10);
    return temp;
  });

const parseQuery = (query) =>
  query.map((item) => {
    const temp = item.split(" ");
    return [temp[0], temp[2], temp[4], temp[6], Number.parseInt(temp[7], 10)];
  });

const isRight = (info, query) => {
  for (let idx = 0; idx < info.length - 1; idx++) {
    if (query[idx] === "-") continue;
    if (query[idx] !== info[idx]) return false;
  }
  return true;
};

const getResult = (info, query) =>
  query.map(
    (q) => info.filter((i) => i[4] >= q[4]).filter((i) => isRight(i, q)).length
  );

function solution(info, query) {
  const parsedInfo = parseInfo(info);
  const parsedQuery = parseQuery(query);
  return getResult(parsedInfo, parsedQuery);
}
