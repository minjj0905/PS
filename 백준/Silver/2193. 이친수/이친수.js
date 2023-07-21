const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const dp = new Array(n + 1);

  dp[1] = 1;
  dp[2] = 1;

  for (let i = 3; i <= n; i++) {
    dp[i] = BigInt(dp[i - 1]) + BigInt(dp[i - 2]);
  }

  console.log(dp[n].toString());
};

solution(input);
