import sys
input = sys.stdin.readline

a, b, c = map(int, input().split())

def pow(a, b):
    if b == 0: return 1

    if (b&1):
        n = int(pow(a, (b-1)//2))
        return (a * n * n) % c

    n = int(pow(a, b//2))
    return (n * n) % c

print(pow(a, b))