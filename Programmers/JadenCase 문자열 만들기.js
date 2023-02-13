function solution(s) {
  let arr = s.split(" ");
  let ans = [];
  arr.forEach((element) => {
    let tmp = "";
    if (element) {
      tmp += element[0].toUpperCase();
      tmp += element.slice(1).toLowerCase();
    }
    ans.push(tmp);
  });

  return ans.join(' ');
}
