const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "test.txt";
const input = fs.readFileSync(filePath).toString().trim().split("\n");

const dp = [0, 1, 1, 1, 2, 2, 3, ...new Array(101).fill(-1)];

for (let i = 4; i < 101; i++) {
  dp[i] = dp[i - 3] + dp[i - 2];
}

const solution = (input) => {
  const arr = input.slice(1).map(Number);
  for (let t = Number(input[0]); t > 0; t--) {
    const n = arr.shift();
    console.log(dp[n]);
  }
};

solution(input);
