const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1).map((e) => e.split(' ').map(Number));

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
      }
    }
  }

  arr.forEach((e) => console.log(e.join(' ')));
};

solution(input);
