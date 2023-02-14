function solution(begin, target, words) {
  if (!words.includes(target)) return 0;

  const wordsLen = words.length;
  let answer = 987654321;

  const isChangeable = (s1, s2) => {
    let cnt = 0;
    for (let i = 0; i < wordsLen; i++) {
      if (s1[i] !== s2[i]) cnt++;
    }
    return cnt === 1;
  };

  const graph = new Array(wordsLen)
    .fill(0)
    .map(() => new Array(wordsLen).fill(0));

  for (let i = 0; i < wordsLen; i++) {
    for (let j = i + 1; j < wordsLen; j++) {
      let cnt = 0;
      for (let k = 0; k < words[i].length; k++) {
        if (words[i][k] !== words[j][k]) {
          cnt++;
        }
      }
      if (cnt === 1) {
        graph[i][j] = 1;
        graph[j][i] = 1;
      }
    }
  }

  const q = [];
  const visit = new Array(wordsLen).fill(0);

  for (let i = 0; i < wordsLen; i++) {
    if (isChangeable(begin, words[i])) {
      q.push([i, 1, [...visit]]);
    }
  }

  while (!!q.length) {
    const [idx, cnt, visited] = q.shift();

    if (visited[idx]) continue;
    visited[idx] = 1;

    if (words[idx] === target) {
      answer = Math.min(answer, cnt);
      continue;
    }

    for (let i = 0; i < wordsLen; i++) {
      if (i !== idx && graph[i][idx]) {
        q.push([i, cnt + 1, [...visited]]);
      }
    }
  }

  return answer;
}

console.log(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]));
console.log(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]));
