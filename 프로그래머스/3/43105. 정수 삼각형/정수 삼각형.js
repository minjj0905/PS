function solution(triangle) {
   
    
    for(let i=1; i<triangle.length; i++) {
        for (let j=0; j<i+1; j++) {
            triangle[i][j] += Math.max(triangle[i-1][j-1] || 0, triangle[i-1][j] || 0);
        }
    }
    
    return Math.max(...triangle[triangle.length - 1]);
}