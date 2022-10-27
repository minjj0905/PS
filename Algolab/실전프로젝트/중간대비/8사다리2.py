import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n, m, d = map(int, sys.stdin.readline().split())
    arr = []
    ans = []
    
    for _ in range(m):
        arr.append(sys.stdin.readline().rstrip())
    
    cur = 2*(d-1)
    arr.pop()
    
    for _ in range(1, m):
        line = arr.pop()
        if line[0] == '?': break
        if 0 < cur-1 < 2*(n-1) and line[cur-1] == '+':
            cur -= 2
        elif 0 < cur+1 < 2*(n-1) and line[cur+1] == '+':
            cur += 2
    
    arr.reverse()
    
    straight = cur
    for line in arr:
        if 0 < straight-1 < 2*(n-1) and line[straight-1] == '+':
            straight -= 2
        elif 0 < straight+1 < 2*(n-1) and line[straight+1] == '+':
            straight += 2
    ans.append(straight//2 + 1)
    
    left = cur-2
    if left >= 0:
        for line in arr:
            if 0 < left-1 < 2*(n-1) and line[left-1] == '+':
                left -= 2
            elif 0 < left+1 < 2*(n-1) and line[left+1] == '+':
                left += 2
        ans.append(left//2 + 1)
    
    right = cur + 2
    if right <= 2*(n-1):
        for line in arr:
            if 0 < right-1 < 2*(n-1) and line[right-1] == '+':
                right -= 2
            elif 0 < right+1 < 2*(n-1) and line[right+1] == '+':
                right += 2
        ans.append(right//2 + 1)
    
    ans.sort()
    s = ' '.join(map(str, ans))
    print(s)