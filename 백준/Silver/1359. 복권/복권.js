const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split(' ');

const perm = (n, r) => {
  let res = 1;
  for (let i = n; i > n - r; i--) {
    res *= i;
  }
  return res;
};

const comb = (n, r) => {
  let res = perm(n, r);
  for (let i = 2; i <= r; i++) {
    res /= i;
  }
  return res;
};

const solution = (input) => {
  const [n, m, k] = input.map(Number);

  let ans = 0;
  for (let i = k; i <= m; i++) {
    ans += comb(m, i) * comb(n - m, m - i);
  }

  console.log(ans / comb(n, m));
};

solution(input);
