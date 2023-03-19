const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim();

const solution = (input) => {
  const n = Number(input);

  const dp = new Array(n + 1).fill(0);

  dp[1] = 1;
  dp[2] = 3;
  for (let i = 3; i <= n; i++) {
    dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
  }

  console.log(dp[n]);
};

solution(input);
