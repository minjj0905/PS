const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const getParent = (parent, x) => {
  if (parent[x] === x) return x;
  return (parent[x] = getParent(parent, parent[x]));
};

const unionParent = (parent, x, y) => {
  const a = getParent(parent, x);
  const b = getParent(parent, y);

  return a < b ? (parent[b] = a) : (parent[a] = b);
};

const findParent = (parent, x, y) => {
  const a = getParent(parent, x);
  const b = getParent(parent, y);
  return a === b;
};

const solution = (input) => {
  const n = Number(input[0]);
  const m = Number(input[1]);
  const edges = [];
  const parents = Array.from(Array(n + 1).keys());

  for (let i = 0; i < m; i++) {
    edges.push(input[2 + i].split(' ').map(Number));
  }
  edges.sort((a, b) => a[2] - b[2]);

  let ans = 0;
  for (let i = 0; i < m; i++) {
    if (!findParent(parents, edges[i][0], edges[i][1])) {
      ans += edges[i][2];
      unionParent(parents, edges[i][0], edges[i][1]);
    }
  }

  console.log(ans);
};

solution(input);
