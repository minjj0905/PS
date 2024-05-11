function solution(numbers, target) {
    let ans = 0;
    
    const dfs = (idx, num) => {
        if (idx === numbers.length) {
            if (num === target) ans++; 
            return;
        }
        
        dfs(idx+1, num + numbers[idx]);
        dfs(idx+1, num - numbers[idx]);
    }
    
    dfs(1, numbers[0]);
    dfs(1, -numbers[0]);
    
    return ans;
}