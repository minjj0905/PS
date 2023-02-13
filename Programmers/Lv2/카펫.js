function solution(brown, yellow) {
  let width = 0;
  let height = 0;

  let sum = brown / 2 + 2;

  if (Number.isInteger(Math.sqrt(yellow))) return [sum / 2, sum / 2];

  for (let i = 1; i < sum / 2; i++) {
    if (yellow % i) continue;

    if (yellow / i + i + 4 === sum) {
      width = yellow / i + 2;
      height = i + 2;
      break;
    }
  }
  return [width, height];
}

// 다른 사람의 풀이
function solution2(brown, yellow) {
  const x = (brown - 12) * 0.5;
  const y = yellow - brown + 8;
  const i = (8 + x + Math.sqrt(Math.pow(x, 2) - 4 * y)) * 0.5;
  const j = (8 + x - Math.sqrt(Math.pow(x, 2) - 4 * y)) * 0.5;
  console.log(i);

  var answer = [i, j];
  return answer;
}
