import sys
input = sys.stdin.readline

h, m = 0, 0
for _ in range(5):
    start, end = input().split()
    start = list(map(int, start.split(":")))
    end = list(map(int, end.split(":")))

    h += end[0] - start[0]
    m += end[1] - start[1]

print(h*60 + m)
