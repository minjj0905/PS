const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n, m, k] = input[0].split(' ').map(Number);
  const arr = new Array(n + 1).fill().map(() => new Array(m + 1).fill(0));

  let ans = 0;
  let cnt = 0;

  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];

  const dfs = (row, col) => {
    if (row < 1 || row > n || col < 1 || col > m) return;

    if (!arr[row][col]) return;

    arr[row][col] = 0;
    cnt++;
    for (let d = 0; d < 4; d++) {
      const ny = row + dy[d];
      const nx = col + dx[d];
      dfs(ny, nx);
    }
  };

  for (let i = 1; i <= k; i++) {
    const [r, c] = input[i].split(' ').map(Number);
    arr[r][c] = 1;
  }

  for (let i = 1; i <= k; i++) {
    const [r, c] = input[i].split(' ').map(Number);
    cnt = 0;
    dfs(r, c, 1);
    ans = ans > cnt ? ans : cnt;
  }

  console.log(ans);
};

solution(input);
