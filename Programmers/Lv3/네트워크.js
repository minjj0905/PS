function solution(n, computers) {
  let answer = 0;

  const visited = new Array(n).fill(0);

  const dfs = (e) => {
    if (visited[e]) return;

    visited[e] = 1;

    for (let i = 0; i < n; i++) {
      if (computers[e][i]) dfs(i);
    }
  };

  for (let i = 0; i < n; i++) {
    if (visited.indexOf(0) !== -1) {
      dfs(visited.indexOf(0));
      answer++;
    }
  }

  return answer;
}
