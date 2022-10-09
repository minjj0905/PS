import sys

s = sys.stdin.readline()

cnt_0 = 0
cnt_1 = 0
prev = s[0]

for n in s[1:]:
    if prev != n:
        if prev == "0": cnt_0 += 1
        else: cnt_1 += 1
        prev = n
    
sys.stdout.write(str(min(cnt_0, cnt_1)) + '\n')