const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input[1].split(' ').map(Number);
  const order = new Array(n).fill().map((e, i) => i);

  order.sort((a, b) => arr[a] - arr[b]);

  let sum = arr[order[0]];
  let acc = arr[order[0]];
  for (let i = 1; i < n; i++) {
    acc += arr[order[i]];
    sum += acc;
  }

  console.log(sum);
};

solution(input);
