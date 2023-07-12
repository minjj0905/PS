const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [h, w] = input[0].split(' ').map(Number);
  const arr = new Array(h).fill().map(() => new Array(w).fill(0));

  const rains = input[1].split(' ').map(Number);

  for (let i = 0; i < w; i++) {
    while (rains[i]) {
      arr[rains[i] - 1][i] = 1;
      rains[i]--;
    }
  }

  let ans = 0;

  for (let i = 0; i < h; i++) {
    let l = 0;
    let cnt = 0;

    for (let j = 0; j < w; j++) {
      if (!l && arr[i][j]) {
        l = 1;
        continue;
      }

      if (l) {
        if (arr[i][j]) {
          ans += cnt;
          cnt = 0;
        } else cnt++;
      }
    }
  }

  console.log(ans);
};

solution(input);
