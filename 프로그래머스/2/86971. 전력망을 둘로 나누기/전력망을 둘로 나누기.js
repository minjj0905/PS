function solution(n, wires) {
    let ans = Infinity;
    const tree = Array.from({ length: n+1 }, () => []);
    wires.forEach(([a, b]) => {
        tree[a].push(b);
        tree[b].push(a);
    });
    
    
    const bfs = (root, except) => {
        let cnt = 0;
        const visit = [];
        const q = [root];
        visit[root] = true;
        
        while(q.length) {
            const idx = q.pop();
            tree[idx].forEach((e) => {
                if(e !== except && !visit[e]) {
                    visit[e] = true;
                    q.push(e);
                }
            })
            cnt++;
        }
        return cnt;
    }
    
    wires.forEach(([a, b]) => {
        ans = Math.min(ans, Math.abs(bfs(a, b) - bfs(b, a)))
    });
    
    return ans;
}