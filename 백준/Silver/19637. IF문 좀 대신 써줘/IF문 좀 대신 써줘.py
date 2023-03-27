import sys
input = sys.stdin.readline

n, m = map(int, input().split())
names = []

for _ in range(n):
    a, b = input().split()
    names.append([a, int(b)])

for _ in range(m):
    num = int(input())

    l = 0
    r = len(names)-1
    ans = 0

    while l <= r:
        m = (l+r)//2
        if names[m][1] >= num:
            r = m-1
            ans = m
        else:
            l = m+1
    
    print(names[ans][0])