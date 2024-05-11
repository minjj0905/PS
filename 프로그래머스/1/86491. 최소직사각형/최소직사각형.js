function solution(sizes) {
    let width = 0;
    let height = 0;
    
    sizes.forEach(([w, h]) => {
        const a = Math.max(w, h);
        const b = Math.min(w, h);
        width = Math.max(width, a);
        height = Math.max(height, b);
    });
    
    return width * height;
}