import sys
input = sys.stdin.readline

def solution(m, n, x, y):
    while x <= m * n:
        if (x-y) % n == 0:
            return x
        x += M
    return -1

t = int(input())
for _ in range(t):
    M, N, x, y = map(int, input().split())
    print(solution(M, N, x, y))
