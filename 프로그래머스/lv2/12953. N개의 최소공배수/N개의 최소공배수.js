function solution(arr) {
    arr.sort((a, b) => b-a);
    let ans = arr[0];
    
    const gcd = (a, b) => {
        if(!b) return a;
        if(!a%b) return b;
        return gcd(b, a%b);
    }
    
    for(let i=1; i<arr.length; i++) {
        if(!ans % arr[i]) continue;
        const b = arr[i];
        
        const g = gcd(ans, b);
        ans = ans * b / gcd(ans,b);
    }
    
    return ans;
}