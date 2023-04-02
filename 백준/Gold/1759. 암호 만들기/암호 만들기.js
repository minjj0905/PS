const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [l, c] = input[0].split(' ').map(Number);
  const arr = input[1].split(' ');
  const ans = new Set();

  arr.sort();

  const aeiou = /[aeiou]/g;

  const isPromising = (x, s) => {
    if (l - x === 1) {
      if (!s.join('').match(aeiou)) return false;
      if (s.join('').match(aeiou).length > l - 2) return false;
    }
    return true;
  };

  const makePW = (x, s, idx) => {
    if (x === l) {
      ans.add(s.join(''));
      return;
    }

    for (let i = idx + 1; i < c; i++) {
      s[x] = arr[i];
      if (isPromising(x, s)) makePW(x + 1, s, i);
    }
  };

  makePW(0, new Array(l).fill(''), -1);
  console.log([...ans].sort().join('\n'));
};

solution(input);
