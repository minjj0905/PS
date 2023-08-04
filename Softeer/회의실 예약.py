import sys
input = sys.stdin.readline

n, m = map(int, input().split())
time = {}
title = []

for _ in range(n):
    name = input().rstrip()
    title.append(name)
    time[name] = [0 for _ in range(9)] + [1 for _ in range(9)]

title.sort()

for _ in range(m):
    room, s, e = input().split()
    e = int(e)
    s = int(s)
    for i in range(e-s):
        time[room][s + i] = 0


for name in range(n):
    print(f"Room {title[name]}:")
    ans = []
    cnt = 0
    for i in range(9, 18):
        if time[title[name]][i]:
            cnt += 1
        elif cnt:
            ans.append(f'{str(i-cnt).zfill(2)}-{str(i).zfill(2)}')
            cnt = 0

    if cnt:
        ans.append(f'{str(18-cnt).zfill(2)}-{str(18).zfill(2)}')

    if len(ans):
        print(f"{len(ans)} available:")
        for res in ans:
            print(res)
    else:
        print("Not available")

    if name != n-1:
        print('-----')
