import sys
input = sys.stdin.readline

x = int(input().rstrip())
n = int(input().rstrip())
s = 0
for _ in range(n):
    a,b = map(int, input().split())
    s += a*b

print("Yes" if x == s else "No")