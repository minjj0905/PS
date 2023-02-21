const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1).map((e) => e.split(''));

  const getMax = (arr) => {
    let m = 0;
    let prev;
    let cnt;

    for (let i = 0; i < n; i++) {
      cnt = 1;

      const tmp = arr[i];
      prev = tmp[0];
      for (let j = 1; j < n; j++) {
        if (prev === tmp[j]) cnt++;
        else cnt = 1;

        prev = tmp[j];
        m = Math.max(m, cnt);
        if (m === n) return n;
      }
    }

    for (let i = 0; i < n; i++) {
      cnt = 1;
      const tmp = arr.map((e) => e[i]);
      prev = tmp[0];
      for (let j = 1; j < n; j++) {
        if (prev === tmp[j]) cnt++;
        else cnt = 1;

        prev = tmp[j];
        m = Math.max(m, cnt);
        if (m === n) return n;
      }
    }

    return m;
  };

  let ans = 1;

  const dy = [-1, 1, 0, 0];
  const dx = [0, 0, -1, 1];

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      for (let d = 0; d < 4; d++) {
        const cy = i + dy[d];
        const cx = j + dx[d];
        if (cy < 0 || cx < 0 || cy >= n || cx >= n) continue;

        const change = arr[cy][cx];
        if (change === arr[i][j]) continue;

        const copy = JSON.parse(JSON.stringify(arr));
        copy[cy][cx] = arr[i][j];
        copy[i][j] = change;

        ans = Math.max(ans, getMax(copy));
        if (ans === n) return n;
      }
    }
  }

  return ans;
};

console.log(solution(input));
