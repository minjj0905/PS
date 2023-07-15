const fs = require('fs');
const filePath = process.platform === 'linux' ? '/dev/stdin' : 'tt.txt';
const input = fs.readFileSync(filePath).toString().trim().split('\n');

const dy = [-1, 1, 0, 0];
const dx = [0, 0, -1, 1];

const solution = (input) => {
  const [r, c, t] = input[0].split(' ').map(Number);
  let arr = [];
  let airCleaner = undefined;
  let ans = 0;

  for (let i = 0; i < r; i++) {
    arr.push(input[i + 1].split(' ').map(Number));
    ans += arr[i].reduce((acc, cur) => (cur === -1 ? 0 : acc + cur), 0);
    if (!airCleaner && arr[i][0] === -1) airCleaner = i;
  }

  // 미세먼지 확산
  const spread = () => {
    const spreadArr = new Array(r).fill().map(() => new Array(c).fill(0));

    for (let i = 0; i < r; i++) {
      for (let j = 0; j < c; j++) {
        if (arr[i][j] === -1) continue;
        const spreadDust = parseInt(arr[i][j] / 5);

        let spreadCnt = 0;
        if (spreadDust)
          for (let d = 0; d < 4; d++) {
            const [ny, nx] = [i + dy[d], j + dx[d]];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if (nx === 0 && (ny === airCleaner || ny === airCleaner + 1)) continue;

            spreadArr[ny][nx] += spreadDust;
            spreadCnt++;
          }
        spreadArr[i][j] -= spreadDust * spreadCnt;
      }
    }
    arr = arr.map((row, y) => row.map((cur, x) => cur + spreadArr[y][x]));
  };

  // 공기청정기 작동
  const runCleaner = () => {
    // 바람의 역방향부터 순차이동
    // 없어지는 먼지
    ans -= arr[airCleaner - 1][0] + arr[airCleaner + 2][0];
    arr[airCleaner - 1][0] = 0;
    arr[airCleaner + 2][0] = 0;

    // 상부 오 위 왼 아 -> 아 왼 위 오
    for (let i = airCleaner - 1; i > 0; i--) {
      arr[i][0] = arr[i - 1][0];
    }

    for (let i = 0; i < c - 1; i++) {
      arr[0][i] = arr[0][i + 1];
    }

    for (let i = 0; i < airCleaner; i++) {
      arr[i][c - 1] = arr[i + 1][c - 1];
    }

    for (let i = c - 1; i > 1; i--) {
      arr[airCleaner][i] = arr[airCleaner][i - 1];
    }
    arr[airCleaner][1] = 0;

    // 하부 오 아 왼 위 -> 위 왼 아 오
    for (let i = airCleaner + 2; i < r - 1; i++) {
      arr[i][0] = arr[i + 1][0];
    }

    for (let i = 0; i < c - 1; i++) {
      arr[r - 1][i] = arr[r - 1][i + 1];
    }

    for (let i = r - 1; i > airCleaner + 1; i--) {
      arr[i][c - 1] = arr[i - 1][c - 1];
    }

    for (let i = c - 1; i > 1; i--) {
      arr[airCleaner + 1][i] = arr[airCleaner + 1][i - 1];
    }
    arr[airCleaner + 1][1] = 0;
  };

  for (let sec = 0; sec < t; sec++) {
    spread();
    // arr.forEach((e) => console.log(e.join(' ')));
    // console.log('--');
    runCleaner();
    // arr.forEach((e) => console.log(e.join(' ')));
    // console.log(ans);
    // console.log();
  }
  console.log(ans > 0 ? ans : 0);
};

solution(input);
