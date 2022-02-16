const removeElem = (numbers, elemIdx) =>
  numbers.filter((_, idx) => idx !== elemIdx);

const generateNumber = (numbers, length) =>
  length === 1
    ? numbers.map((number) => [number])
    : numbers.reduce(
        (prev, cur, curIdx) => [
          ...prev,
          ...generateNumber(removeElem(numbers, curIdx), length - 1).map(
            (permutation) => [cur, ...permutation]
          ),
        ],
        []
      );

const isPrime = (number) => {
  if ([0, 1].includes(number)) return false;
  else if (number === 2) return true;
  else {
    const sqrt = number ** 0.5;
    for (let quotient = 2; quotient <= sqrt; quotient++) {
      if (number % quotient === 0) {
        return false;
      }
    }
    return true;
  }
};

function solution(numbers) {
  const answer = Array(
    ...new Set(
      Array.from({ length: numbers.length }, (_, idx) => idx + 1).reduce(
        (prev, length) =>
          prev.concat(
            generateNumber(numbers.split(""), length).map((arrNumbers) =>
              Number(arrNumbers.join(""))
            )
          ),
        []
      )
    )
  ).filter((elem) => isPrime(elem)).length;
  return answer;
}

console.log(solution("456"));
