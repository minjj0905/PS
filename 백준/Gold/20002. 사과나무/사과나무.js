const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = [];
  let ans = -1000;

  const pre = new Array(n).fill().map(() => new Array(n).fill(0));

  for (let i = 0; i < n; i++) {
    arr.push(input[1 + i].split(' ').map(Number));
    ans = Math.max(ans, ...arr[i]);

    for (let j = 0; j < n; j++) {
      pre[i][j] += arr[i][j];
      if (i > 0) pre[i][j] += pre[i - 1][j];
      if (j > 0) pre[i][j] += pre[i][j - 1];
      if (i > 0 && j > 0) pre[i][j] -= pre[i - 1][j - 1];
    }
  }

  for (let k = 1; k < n; k++) {
    for (let i = 0; i < n - k; i++) {
      for (let j = 0; j < n - k; j++) {
        let sum = pre[i + k][j + k];
        if (i > 0) sum -= pre[i - 1][j + k];
        if (j > 0) sum -= pre[i + k][j - 1];
        if (i > 0 && j > 0) sum += pre[i - 1][j - 1];

        ans = Math.max(ans, sum);
      }
    }
  }
  console.log(ans);
};

solution(input);
