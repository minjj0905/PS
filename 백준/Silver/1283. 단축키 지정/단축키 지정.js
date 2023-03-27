const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'test.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const solution = input => {
  const n = Number(input[0]);
  const arr = input.slice(1);
  const hotkey = new Array(26).fill(0);
  
  const res = arr.map(e => {
    const lst = e.split(' ');
    if(lst.length > 1) {
      for(let word = 0; word<lst.length; word++) {
        if(!hotkey[lst[word].toLowerCase().charCodeAt(0) - 97]) {
          hotkey[lst[word].toLowerCase().charCodeAt(0) - 97] = 1;
          lst[word] = '[' + lst[word][0] + ']' + lst[word].substr(1);
          return lst.join(' ');
        }
      }
    }
    for(let i=0; i<e.length; i++) {
      if(e[i] !== ' ' && !hotkey[e.toLowerCase().charCodeAt(i) - 97]) {
        hotkey[e.toLowerCase().charCodeAt(i) - 97] = 1
        return e.substr(0, i) + '[' + e[i] + ']' + e.substr(i+1);
      }
    }
    return e;
  })

  res.forEach((e) => console.log(e));
};

solution(input);