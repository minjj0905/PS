const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const arr = [input[0], input[1], input[2]].map(Number);

  arr.sort((a, b) => a - b);

  console.log(arr[1]);
};

solution(input);
