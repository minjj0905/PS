const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [n, m] = input[0].split(' ').map(Number);
  const arr = input[1].split(' ').map(Number);

  const ans = new Set();

  const isPrime = (num) => {
    for (let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i == 0) return 0;
    }
    return 1;
  };
  const select = new Array(n).fill(0);

  const sol = (cnt) => {
    if (cnt == m) {
      const sum = select.reduce((acc, cur, idx) => (cur ? acc + arr[idx] : acc), 0);
      if (isPrime(sum)) ans.add(sum);
      return;
    }

    for (let i = 0; i < n; i++) {
      if (select[i]) continue;
      select[i] = 1;
      sol(cnt + 1);
      select[i] = 0;
    }
  };

  sol(0);
  if (ans.size == 0) {
    console.log(-1);
    return;
  }
  console.log([...ans].sort((a, b) => a - b).join(' '));
};

solution(input);
