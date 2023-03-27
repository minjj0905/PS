n = int(input())
check = n
cyclenum = 0
cnt = 0

while True:
    temp = n//10 + n%10
    cyclenum = (n%10)*10 + temp%10
    cnt += 1
    n = cyclenum
    if cyclenum == check:
        break

print(cnt)