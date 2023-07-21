const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = new Array(n).fill().map((e, i) => i + 1);
  const ans = [];

  while (arr.length !== 1) {
    ans.push(arr.shift());
    arr.push(arr.shift());
  }
  ans.push(arr.shift());
  console.log(ans.join(' '));
};

solution(input);
