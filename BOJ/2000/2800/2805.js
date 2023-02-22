const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n, m] = input[0].split(' ').map(Number);
  const arr = input[1].split(' ').map(Number);
  arr.sort((a, b) => a - b);

  let ans = -Infinity;

  let l = 0;
  let r = arr[n - 1];

  let mid;

  while (l <= r) {
    mid = Math.floor((l + r) / 2);
    const res = arr.reduce((acc, cur) => {
      if (cur > mid) acc += cur - mid;
      return acc;
    }, 0);

    if (res >= m) {
      ans = Math.max(ans, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  console.log(ans);
};

solution(input);
