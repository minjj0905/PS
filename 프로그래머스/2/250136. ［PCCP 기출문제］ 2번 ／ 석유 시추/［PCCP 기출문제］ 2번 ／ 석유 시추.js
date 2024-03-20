function solution(land) {
    const n = land.length;
    const m = land[0].length;
    const res = Array(m).fill(0);
    const visited = Array.from({length: n}, () => Array(m).fill(0));
    const oil = [];
    
    const dy = [0, 0, -1, 1];
    const dx = [-1, 1, 0, 0];
    
    const bfs = (a, b) => {
        let size = 0, start = Infinity, end = -Infinity;
        visited[a][b] = 1;
        
        const q = [];
        q.push([a, b]);
        
        while (q.length) {
            const [x, y] = q.shift();
            size++;
            start = Math.min(start, y);
            end = Math.max(end, y);
            
            for(let i=0; i<4; i++) {
                const nx = x + dx[i];
                const ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(!visited[nx][ny] && land[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push([nx, ny]);
                }
            }
        }
        oil.push({size, start, end});
    }
    
    for (let i=0; i<n; i++) {
        for (let j=0; j<m; j++) {
            if(!visited[i][j] && land[i][j]) bfs(i, j);
        }
    }
    
    oil.forEach(o => {
        for(let i=o.start; i<=o.end; i++) {
            res[i] += o.size;
        }
    })
    
    return Math.max(...res);
}