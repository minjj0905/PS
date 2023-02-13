const fs = require('fs');
const input = fs.readFileSync('test.txt').toString().trim().split('\n');

const dx = [0, 0, 1, -1];
const dy = [1, -1, 0, 0];

const solution = (input) => {
  const [m, n] = input[0].split(' ').map(Number);
  const map = input.slice(1).map((element) => element.split(' ').map(Number));

  const queue = [];

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (map[i][j] == 1) queue.push([i, j, 0]);
    }
  }

  while (queue.length) {
    const [y, x, day] = queue.shift();

    for(let d=0; d<4; d++) {
      let nx = x + dx[d];
      let ny = y + dy[d];

      if(nx >= 0 && nx < m && ny >= 0 && ny < n) {
        let cur = map[ny][nx];

        if(cur == 1) continue;
        
      }
    }
  }
};

solution(input);
