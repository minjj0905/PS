function solution(n) {
  let ans = 0;

  while(n) {
    if(n & 1) {
      n--;
      ans++;
    } else {
      n /= 2;
    }
  }

  return ans;
}
