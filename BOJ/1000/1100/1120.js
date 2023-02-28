const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split(' ');

const solution = (input) => {
  let [A, B] = input;
  let ans = Infinity;

  const diff = B.length - A.length;

  for (let i = 0; i <= diff; i++) {
    let cnt = 0;

    for (let j = i; j < i + A.length; j++) {
      if (A[j - i] !== B[j]) cnt++;
    }

    ans = Math.min(ans, cnt);
  }

  console.log(ans);
};

solution(input);
