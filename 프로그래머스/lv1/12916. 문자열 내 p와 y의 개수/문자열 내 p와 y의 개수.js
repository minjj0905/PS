function solution(s){
    const regP = /p/g;
    const regY = /y/g;
    s = s.toLowerCase();
    
    const p = s.match(regP);
    const y = s.match(regY);
    
    if(p===y) return true;
    if(!p || !y) return false;
    
    return s.match(regP).length === s.match(regY).length ? true : false;
}