const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const t = Number(input[0]);

  for (let tc = 1; tc <= t; tc++) {
    let [n, m] = input[2 * tc - 1].split(' ').map(Number);
    const arr = input[2 * tc].split(' ').map(Number);

    let max = Math.max(...arr);
    let ans = 0;

    while (1) {
      const cur = arr.shift();

      if (cur < max) {
        arr.push(cur);
        if (m) m--;
        else m = n - 1;
        continue;
      }

      if (!m) {
        ans++;
        break;
      }

      ans++;
      n--;
      m--;
      max = Math.max(...arr);
    }

    console.log(ans);
  }
};

solution(input);
