function solution(people, limit) {
  let answer = 0;
  people.sort((a, b) => b - a);

  let l = 0;
  let r = people.length - 1;

  while (l < r) {
    if (people[l] + people[r] > limit) l++;
    else {
      l++;
      r--;
    }
    answer++;
  }

  if (l == r) answer++;
  return answer;
}
