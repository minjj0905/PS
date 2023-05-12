import sys
input = sys.stdin.readline

n = int(input())

width = 3
for i in range(1, n):
    width = width * 2 - 1

print(width**2)
