import sys
input = sys.stdin.readline

a, b = map(int, input().split())
if a > b:
    print(a)
elif a < b:
    print(b)
else:
    print("same")
