import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n = int(sys.stdin.readline())
    dic = {}
    for _ in range(n):
        a, b = sys.stdin.readline().split()
        if b in dic: dic[b].append(a)
        else: dic[b] = [a]

    res = 1
    for key, value in dic.items():
        res *= len(value)+1

    if n == 0:
        print(0)
    else:
        print(res-1) 