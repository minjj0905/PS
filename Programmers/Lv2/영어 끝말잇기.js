function solution(n, words) {
  let used = new Set();
  let user = 1;
  used.add(words[0]);

  for (let i = 1; i < words.length; i++) {
    user++;
    if (user > n) user %= n;

    let past_word = words[i - 1];
    let current_word = words[i];

    if (past_word.at(-1) != current_word[0])
      return [user, Math.ceil((i + 1) / n)];

    if (used.has(current_word)) return [user, Math.ceil((i + 1) / n)];

    used.add(current_word);
  }

  return [0, 0];
}
