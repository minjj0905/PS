const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n1, n2] = input[0].split(' ').map(Number);
  const a = new Set(input[1].split(' '));
  const b = new Set(input[2].split(' '));

  const set = new Set([...a, ...b]);
  a.forEach((e) => {
    if (b.has(e)) set.delete(e);
  });

  console.log(set.size);
};

solution(input);
