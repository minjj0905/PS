const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim();

const solution = (input) => {
  const n = Number(input);
  let ans = 0;
  const row = new Array(n).fill(0);

  const isPromising = (x) => {
    for (let i = 0; i < x; i++) {
      if (row[x] === row[i] || Math.abs(row[x] - row[i]) === Math.abs(x - i)) return false;
    }
    return true;
  };

  const nQueens = (x) => {
    if (x === n) {
      ans++;
      return;
    }
    for (let i = 0; i < n; i++) {
      row[x] = i;
      if (isPromising(x)) {
        nQueens(x + 1);
      }
    }
  };

  nQueens(0);
  console.log(ans);
};

solution(input);
