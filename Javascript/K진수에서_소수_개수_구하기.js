/*
https://programmers.co.kr/learn/courses/30/lessons/92335
2022 KAKAO BLIND RECRUITMENT k진수에서 소수 개수 구하기

1. 10진법을 k진법으로 변환 (타입은 문자열)
2. split으로 숫자 자르기
3. 숫자가 소수인지 판별
*/

const getDecToK = (n, k) => {
    const remains = [];
    
    while (n > 0)
    {
        remains.push(n % k);
        n = Math.floor(n / k);
    }

    return remains.reverse().map((num) => `${num}`).join("");
}

const isPrime = (n) => {
    if (n === 0 || n === 1)
        return false;
    if (n === 2)
        return true;

	const sqrt = n ** 0.5;
    for (let target = 2; target <= sqrt; target++)
    {
        if (n % target === 0)
            return false;
    }
    return true;
}

function solution(n, k) {
	const stringK = getDecToK(n, k);
	const numbers = stringK.split("0").filter(number => number !== "").map((number) => Number.parseInt(number, 10));
    return numbers.filter(number => isPrime(number)).length;
}
