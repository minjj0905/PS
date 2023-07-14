const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n, k] = input[0].split(' ').map(Number);
  const arr = [];

  const dp = new Array(n + 1).fill().map(() => new Array(k + 1).fill(0));
  for (let i = 0; i < n; i++) {
    const item = input[i + 1].split(' ').map(Number);
    arr.push({ w: item[0], v: item[1] });
  }

  for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= k; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j - arr[i - 1].w >= 0) {
        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - arr[i - 1].w] + arr[i - 1].v);
      }
    }
  }

  console.log(dp[n][k]);
};

solution(input);
