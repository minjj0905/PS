function solution(n, info) {
  let max_score = 0;
  let ryan = Array(11).fill(0);

  // 함수선언부
  const dfs = (a_score, r_score, idx, count, arr) => {
    if(count > n) return;

    // idx 과녁의 점수
    if(idx > 10) {
      const diff = r_score - a_score;

      if(diff > max_score) {
        max_score = diff;
        arr[10] = n - count;
        ryan = arr;
      }
      return;
    }

    if(count < n) {
      let temp = [...arr];

      temp[10 - idx] = info[10 - idx] + 1;
      // 라이언이 이기는거
      dfs(a_score, r_score+idx, idx+1, count + temp[10-idx], temp);
    }

    if(info[10 - idx] > 0) {
      // 어피치가 이기는거
      dfs(a_score + idx, r_score, idx+1, count, arr);
    } else {
      // 0 : 0
      dfs(a_score, r_score, idx + 1, count, arr);
    }
  }

  dfs(0, 0, 0, 0, ryan);

  return max_score >= 0 ? ryan : [-1];
}

console.log(solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]));