const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const solution = (input) => {
  const n = Number(input[0]);
  const arr = input.slice(1).map((e) => e.split(" ").map(Number));
  let rank = "";

  for (let i = 0; i < arr.length; i++) {
    let cnt = 0;
    for (let j = 0; j < arr.length; j++) {
      const [x, y] = arr[i];
      const [p, q] = arr[j];

      if (x < p && y < q) cnt++;
    }
    rank += cnt + 1 + " ";
  }
  console.log(rank);
};

solution(input);
