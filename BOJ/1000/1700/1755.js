const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split(' ');

const solution = (input) => {
  const [m, n] = input.map(Number);

  const arr = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];

  const ans = [];
  for (let i = m; i <= n; i++) {
    ans.push(i);
  }

  const order = (a, b) => {
    let textA = '';
    let textB = '';

    const strA = a.toString();
    [...strA].forEach((c) => {
      textA += arr[Number(c)];
    });
    const strB = b.toString();
    [...strB].forEach((c) => {
      textB += arr[Number(c)];
    });

    return textA < textB ? -1 : textA > textB ? 1 : 0;
  };

  ans.sort((a, b) => order(a, b));

  for (let i = 0; i < ans.length; i += 10) {
    console.log(ans.slice(i, i + 10).join(' '));
  }
};

solution(input);
