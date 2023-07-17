const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const m = Number(input[1]);

  const arr = new Array(n).fill().map(() => new Array(n).fill(Infinity));

  for (let i = 0; i < n; i++) arr[i][i] = 0;

  for (let i = 0; i < m; i++) {
    const [a, b, c] = input[2 + i].split(' ').map(Number);
    arr[a - 1][b - 1] = Math.min(arr[a - 1][b - 1], c);
  }

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (arr[i][k] + arr[k][j] < arr[i][j]) arr[i][j] = arr[i][k] + arr[k][j];
      }
    }
  }

  arr.forEach((e) => console.log(e.map((e) => (e === Infinity ? 0 : e)).join(' ')));
};

solution(input);
