const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = (input) => {
  const arr = input.slice(1).map((e) => e.split(' ').map(Number));
  let sum = 0;
  let xor = 0;

  arr.forEach((query) => {
    switch (query[0]) {
      case 1:
        sum += query[1];
        xor ^= query[1];
        break;
      case 2:
        sum -= query[1];
        xor ^= query[1];
        break;
      case 3:
        console.log(sum);
        break;
      case 4:
        console.log(xor);
        break;
      default:
        break;
    }
  });
};

solution(input);

// 맞왜틀