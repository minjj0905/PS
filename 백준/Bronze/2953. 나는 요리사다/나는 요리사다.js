const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const arr = input.map((e) => e.split(' ').map(Number));
  const sum = arr.map((e) => e.reduce((a, b) => a + b, 0));
  const max = Math.max(...sum);
  const max_idx = sum.indexOf(max);

  console.log(max_idx + 1, max);
};

solution(input);
