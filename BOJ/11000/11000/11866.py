import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())

q = deque([i for i in range(1, n+1)])
ans = []

while q:
    q.rotate(-(k-1))
    ans.append(q.popleft())

sys.stdout.write('<' + ', '.join(map(str, ans)) + '>')

