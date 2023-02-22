const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1).map(Number);
  const dp = new Array(n).fill(0).map(() => new Array(2).fill(0));

  dp[0][0] = arr[0];
  if (n > 1) {
    dp[1][0] = arr[1];
    dp[1][1] = arr[0] + arr[1];
  }

  for (let i = 2; i < n; i++) {
    dp[i][0] = Math.max(...dp[i - 2]) + arr[i];
    dp[i][1] = dp[i - 1][0] + arr[i];
  }
  console.log(Math.max(...dp[n - 1]));
};

solution(input);
