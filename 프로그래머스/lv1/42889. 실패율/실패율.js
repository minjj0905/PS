function solution(N, stages) {
    const ans = Array.from(Array(N+1).keys()).slice(1);
    
    const rate = new Array(N+1).fill(0);
    const people = new Array(N+2).fill(0);
    let sum = stages.length;

    for(let i=0; i<sum; i++) {
        people[stages[i]]++;
    }
    
    for(let i=1; i<=N; i++) {
        if(!people[i]) continue;
        rate[i] = people[i] / sum;
        sum -= people[i];
    }
    
    
    ans.sort((a, b) => rate[b] - rate[a]);
    
    return ans;
}