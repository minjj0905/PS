const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1).map((e) => e.split('').map(Number));
  const visit = new Array(n).fill(0).map(() => new Array(n).fill(0));

  const ans = [];

  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];

  const dfs = (y, x, idx) => {
    arr[y][x] = idx;
    visit[y][x] = 1;
    ans[idx]++;

    for (let i = 0; i < 4; i++) {
      const ny = y + dy[i];
      const nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
      if (arr[ny][nx] && !visit[ny][nx]) {
        dfs(ny, nx, idx);
      }
    }
  };

  for (let y = 0; y < n; y++) {
    for (let x = 0; x < n; x++) {
      if (arr[y][x] && !visit[y][x]) {
        ans.push(0);
        dfs(y, x, ans.length - 1);
      }
    }
  }

  ans.sort((a, b) => a - b);
  console.log(ans.length);
  console.log(ans.join('\n'));
};

solution(input);
