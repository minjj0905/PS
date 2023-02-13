const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

const solution = (input) => {
  let [n, k] = input.map(Number);
  const min = (k * (k + 1)) / 2;

  if (min > n) {
    console.log(-1);
    return;
  } else if ((n - min) % k) {
    console.log(k);
  } else {
    console.log(k - 1);
  }
};

solution(input);
