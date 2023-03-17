const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const [r, c] = input[0].split(' ').map(Number);
  const image = input.slice(1, r + 1).map((e) => e.split(' ').map(Number));
  const t = Number(input[r + 1]);

  const filter = new Array(r - 2).fill(0).map(() => new Array(c - 2).fill(0));

  for (let y = 0; y < r - 2; y++) {
    for (let x = 0; x < c - 2; x++) {
      const arr = [];
      arr.push(...image[y].slice(x, x + 3));
      arr.push(...image[y + 1].slice(x, x + 3));
      arr.push(...image[y + 2].slice(x, x + 3));
      arr.sort((a, b) => a - b);
      filter[y][x] = arr[4];
    }
  }

  console.log(
    filter.reduce((acc, cur) => {
      return (acc += cur.filter((e) => e >= t).length);
    }, 0),
  );
};

solution(input);
