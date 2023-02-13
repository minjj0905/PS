const process = (s) => {
  const c = s.replaceAll('0', '');
  const change_cnt = s.length - c.length;    
  return [c, change_cnt];
}

function solution(s) {
  let cnt = 0;
  let res = 0;
  let str = s;

  while(str.length != 1) {
    cnt++;
    let [c, change_cnt] = process(str);
    res += change_cnt;
    str = c.length.toString(2);
  }

  return [cnt, res];
}
