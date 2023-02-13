function solution(s) {
  let stack = [];

  if (s[0] == ")") return false;
  if (s.length == 1) return false;

  for (let i = 0; i < s.length; i++) {
    if (s[i] == "(") {
      stack.push(s[i]);
    } else {
      const p = stack.pop();
      if (p != "(") return false;
    }
  }

  if (stack.length) return false;
  return true;
}
