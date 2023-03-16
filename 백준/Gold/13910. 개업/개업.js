const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n, m] = input[0].split(' ').map(Number);
  const arr = input[1].split(' ').map(Number);

  const dp = new Array(n + 1).fill(Infinity);

  for (let i = 1; i <= n; i++) {
    // 한개
    for (let j = 0; j < m; j++) {
      if (arr[j] < i) {
        dp[i] = Math.min(dp[i], dp[i - arr[j]] + 1);
      }
      if (arr[j] === i) {
        dp[i] = 1;
        break;
      }
    }

    if (dp[i] === 1) continue;

    // 두개
    for (let a = 0; a < m; a++) {
      for (let b = a + 1; b < m; b++) {
        const sum = arr[a] + arr[b];

        if (sum < i) {
          dp[i] = Math.min(dp[i], dp[i - sum] + 1);
        }

        if (sum === i) {
          dp[i] = 1;
          break;
        }
      }
      if (dp[i] === 1) break;
    }
  }
  console.log(dp[n] !== Infinity ? dp[n] : -1);
};

solution(input);
