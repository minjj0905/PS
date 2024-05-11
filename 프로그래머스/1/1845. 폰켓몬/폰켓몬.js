function solution(nums) {
    const ponketmons = new Map();
    
    nums.forEach(e => {
        if(!ponketmons.has(e)) ponketmons.set(e, 1);
    });
    const cnt = ponketmons.size;
    
    return cnt > nums.length/2 ? nums.length/2 : cnt;
}