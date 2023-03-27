a, b, c = map(int, input().split())
n = a*b
if n >= c:
    print(n-c)
else: print(0)