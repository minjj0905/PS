import sys
input = sys.stdin.readline

n = int(input())
arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

arr.sort(key = lambda x: (x[1], x[0]))

start = arr[0][0]
end = arr[0][1]

res = 1

for t in arr[1:]:
    if end <= t[0]:
        res += 1
        start = t[0]
        end = t[1]

print(res)