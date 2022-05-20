export const read = () => {
  let input = require("fs")
    .readFileSync("dev/stdin")
    .toString()
    .trim()
    .split("\n");
  return input;
};
