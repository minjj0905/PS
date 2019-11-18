n = int(input())
xylst = []
for _ in range(n):
    xylst.append(list(map(int, input().split())))

xylst.sort(key = lambda x: (x[1], x[0]))

for xy in xylst:
    print(xy[0], xy[1])