import sys
input = sys.stdin.readline

a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

ab = [b[0] - a[0], b[1] - a[1]]
bc = [c[0] - b[0], c[1] - b[1]]

x = ab[0]*bc[1] - ab[1]*bc[0]

print(x // abs(x) if x else x)