const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1);
  const obj = {};

  let max = 0;
  let max_name = '';

  arr.forEach((e) => {
    if (obj[e]) obj[e]++;
    else obj[e] = 1;

    if (obj[e] === max && e < max_name) max_name = e;
    else if (obj[e] > max) {
      max_name = e;
      max = obj[e];
    }
  });

  console.log(max_name);
};

solution(input);
