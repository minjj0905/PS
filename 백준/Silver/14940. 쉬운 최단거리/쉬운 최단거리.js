const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n, m] = input[0].split(' ').map(Number);
  const grid = input.slice(1).map((e) => e.split(' ').map(Number));

  const ans = new Array(n).fill().map(() => new Array(m).fill(-1));

  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];

  const q = [];

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j] == 2) {
        q.push([i, j, 0]);
        j = m;
        i = n;
      }
    }
  }

  while (q.length) {
    const [y, x, mv] = q.shift();

    if (ans[y][x] !== -1 && ans[y][x] <= mv) continue;
    ans[y][x] = mv;

    for (let d = 0; d < 4; d++) {
      const [ny, nx] = [y + dy[d], x + dx[d]];
      if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

      if ((grid[ny][nx] && ans[ny][nx] === -1) || ans[ny][nx] > mv + 1) {
        q.push([ny, nx, mv + 1]);
      }
    }
  }

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (grid[i][j] == 0) {
        ans[i][j] = 0;
      }
    }
  }

  ans.forEach((line) => {
    console.log(line.join(' '));
  });
};

solution(input);
