const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const solution = (input) => {
  m = Number(input[0]);
  n = Number(input[1]);

  let ans = [];

  const isPrime = (number) => {
    if (number === 1) return false;
    for (let i = 2; i <= Math.sqrt(number); i++) {
      if (number % i === 0) return false;
    }
    return true;
  };

  for (let i = m; i <= n; i++) {
    if (isPrime(i)) ans.push(i);
  }

  if (!ans.length) console.log(-1);
  else {
    console.log(ans.reduce((a, b) => a + b, 0));
    console.log(Math.min(...ans));
  }
};

solution(input);
