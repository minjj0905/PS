const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const solution = (input) => {
  const [N, M] = input[0].split(' ').map(Number);
  const arr = [];

  input.slice(1).forEach((element) => arr.push(element.split(' ').map(Number)));

  const dp = new Array(N).fill(0).map(() => new Array(M).fill(0));

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (i > 0) {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j]);
      }
      if (j > 0) {
        dp[i][j] = Math.max(dp[i][j - 1], dp[i][j]);
      }

      dp[i][j] += arr[i][j];
    }
  }

  console.log(dp[N - 1][M - 1]);
};

solution(input);
