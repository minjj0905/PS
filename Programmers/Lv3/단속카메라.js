function solution(routes) {
  let answer = 1;

  routes.sort((a, b) => a[1] - b[1]);
  let prev = routes[0][1];

  routes.slice(1).forEach((e) => {
    if (e[0] > prev || e[1] < prev) {
      prev = e[1];
      answer++;
    }
  });

  return answer;
}
