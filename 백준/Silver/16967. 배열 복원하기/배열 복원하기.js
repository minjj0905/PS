const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [h, w, x, y] = input[0].split(' ').map(Number);
  const arrB = input.slice(1).map((e) => e.split(' ').map(Number));

  for (let i = 0; i < h; i++) {
    for (let j = 0; j < w; j++) {
      arrB[i + x][j + y] -= arrB[i][j];
    }
  }
  for (let i = 0; i < h; i++) {
    console.log(arrB[i].slice(0, -y).join(' '));
  }
};

solution(input);