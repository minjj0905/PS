function solution(n, stations, w) {
  let answer = 0;

  const range = 2 * w + 1;
  let start = 0;
  let end = 0;

  stations.forEach((e) => {
    end = e - w - 1;
    if (end > 0 && end <= n) {
      answer += Math.ceil((end - start + 1) / range);
    }
    start = e + w + 1;
  });

  if (start <= n) {
    answer += Math.ceil((n - start + 1) / range);
  }

  return answer;
}
