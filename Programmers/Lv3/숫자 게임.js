function solution(A, B) {
  let answer = 0;

  A.sort((a, b) => b - a);
  B.sort((a, b) => b - a);

  let idx = 0;
  for (let i = 0; i < A.length; i++) {
    if (A[i] < B[idx]) {
      answer++;
      idx++;
    }
  }

  return answer;
}

console.log(solution([5, 1, 3, 7], [2, 2, 6, 8]));
