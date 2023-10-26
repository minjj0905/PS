def solution(n):
    ans = []
    
    def hanoi(n, start, mid, end):
        if n == 1:
            ans.append([start, end])
            return
        
        hanoi(n-1, start, end, mid)
        hanoi(1, start, mid, end)
        hanoi(n-1, mid, start, end)

    hanoi(n, 1, 2, 3)
    return ans;
        
        
        