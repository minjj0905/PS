const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const s = input[0];
  let t = input[1];

  while (s.length < t.length) {
    if (t[t.length - 1] === 'A') {
      t = t.slice(0, -1);
    } else {
      t = t.slice(0, -1).split('').reverse().join('');
    }
  }

  console.log(s === t ? 1 : 0);
};

solution(input);
