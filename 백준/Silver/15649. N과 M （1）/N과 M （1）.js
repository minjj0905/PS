const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split(' ');

const solution = (input) => {
  const [n, m] = input.map(Number);

  const s = [];

  const dfs = () => {
    if (s.length === m) {
      console.log(s.join(' '));
      return;
    }

    for (let i = 1; i <= n; i++) {
      if (!s.includes(i)) {
        s.push(i);
        dfs();
        s.pop();
      }
    }
  };

  dfs();
};

solution(input);
