function solution(s) {
  let ans = [];

  arr = s.split('},').map((e) => {
    return e
      .replace(/[{}]/g, '')
      .split(',')
      .map(Number)
      .sort((a, b) => a - b);
  });
  arr.sort((a, b) => a.length - b.length);

  ans.push(arr[0][0]);
  arr.slice(1).forEach((e) => {
    e.forEach((n) => {
      if (!ans.includes(n)) ans.push(n);
    });
  });
  return ans;
}
