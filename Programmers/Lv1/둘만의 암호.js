function solution(s, skip, index) {
  let ans = '';

  const strArr = 'abcdefghijklmnopqrstuvwxyz'.split('');
  const skipArr = skip.split('');

  const arr = strArr.filter((e) => !skipArr.includes(e));

  s.split('').map((e) => {
    let idx = arr.indexOf(e);
    idx += index;
    while (idx > arr.length - 1) {
      idx -= arr.length;
    }
    ans += arr[idx];
  });
  return ans;
}

console.log(solution('aukks', 'wbqd', 5));
