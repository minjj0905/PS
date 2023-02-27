function solution(ingredient) {
  let ans = 0;

  let arr = [];
  for(let i=0; i<4; i++) {
    arr.push(ingredient[i]);
  }

  let idx = 4;
  const ingredient_cnt = ingredient.length;
  
  while (idx <= ingredient_cnt) {
    if (JSON.stringify(arr.slice(arr.length - 4)) === JSON.stringify([1,2,3,1])) {
      ans += 1;
      arr.pop();
      arr.pop();
      arr.pop();
      arr.pop();
    }

    if(idx === ingredient_cnt) break;
    arr.push(ingredient[idx]);
    idx++;

  }

  if (JSON.stringify(arr.slice(arr.length - 4)) === JSON.stringify([1, 2, 3, 1])) {
    ans += 1;
  }
    return ans;
}

console.log(solution([1, 1, 2, 1, 2, 3, 1, 3, 1, 2, 3, 1]));
// 빵 야채 고기 빵
// 1 빵 2 야채 3 고기

// 좋은 코드
// function solution(ingredient) {
//   let count = 0;

//   for (let i = 0; i < ingredient.length; i++) {
//     if (ingredient.slice(i, i + 4).join("") === "1231") {
//       count++;
//       ingredient.splice(i, 4);
//       i -= 3;
//     }
//   }

//   return count;
// }