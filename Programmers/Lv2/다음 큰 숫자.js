function solution(n) {
  const binaryN = n.toString(2);

  const countOne = (str) => {
    const res = str.match(/1/g);
    return res.length;
  };

  const targetCnt = countOne(binaryN);
  let ans = n + 1;

  while (countOne(ans.toString(2)) !== targetCnt) {
    ans++;
  }
  return ans;
}

console.log(solution(15));
