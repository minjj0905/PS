import sys
input = sys.stdin.readline

def isEven(arr):
    for element in arr:
        if element&1: return False
    return True


n = int(input())
b = list(map(int, input().split()))
cnt = 0

while sum(b):
    if isEven(b):
        cnt += 1
        b = list(map(lambda x: x//2, b))
    else:
        for i in range(n):
            if b[i]&1:
                cnt += 1
                b[i] -= 1

print(cnt)