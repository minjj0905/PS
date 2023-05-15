const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1).map((e) => e.split(' ').map(Number));
  const grid = new Array(100).fill(0).map(() => new Array(100).fill(0));
  let ans = 0;

  for (const [x, y] of arr) {
    for (let i = 0; i < 10 && i + y < 100; i++) {
      for (let j = 0; j < 10 && j + x < 100; j++) {
        if (grid[i + y][j + x]) continue;
        grid[i + y][j + x] = 1;
        ans++;
      }
    }
  }

  console.log(ans);
};

solution(input);
