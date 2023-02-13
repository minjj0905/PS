const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const solution = (input) => {
  input.forEach((e) => {
    const [n, m] = e.split(' ').map(Number);

    let ans = 0;
    for (let i = n; i <= m; i++) {
      const strI = i.toString();
      const setI = new Set(strI);
      if (setI.size === strI.length) ans++;
    }

    console.log(ans);
  });
};

solution(input);
