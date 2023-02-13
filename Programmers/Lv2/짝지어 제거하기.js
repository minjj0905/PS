function solution(s) {
  let q = [];
  q.push(s[0]);
  [...s.slice(1)].forEach((e) => {
    q.push(e);

    if (q[q.length - 1] === q[q.length - 2]) {
      q.pop();
      q.pop();
    }
  });

  return !q.length ? 1 : 0;
}
