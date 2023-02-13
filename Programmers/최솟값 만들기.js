function solution(A, B) {
  let ans = 0;

  let a = A.sort((a, b) => a - b);
  let b = B.sort((a, b) => b - a);

  for(let i=0; i<A.length; i++) {
    ans += a[i] * b[i];
  }

  return ans;
}
