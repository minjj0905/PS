import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    p = input().rstrip()
    n = int(input())
    arr = input()
    arr = arr[1: -2].split(',')
    
    d = deque()
    d.append(p[0])
    for f in p[1:]:
        if f == "R" == d[-1] == 'R':
                d.pop()
        else:
            d.append(f)

    idx = 0
    for f in d:
        if f == "D":
            arr.pop(idx)
        else:
            idx = -1
    
    if idx == -1
    arr.
