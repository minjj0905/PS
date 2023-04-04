arr = [0] * 10001
i = 1
while 1:
    n = i
    for s in str(i):
        n += int(s)
    if n > 10000: break
    arr[n] = 1
    i = n

for i in range(1, 10001):
    while 1:
        n = i
        for s in str(i):
            n += int(s)
        if n > 10000: break
        if arr[n]: break
        arr[n] = 1
        i = n

for i in range(1, 10001):
    if not arr[i]:
        print(i)