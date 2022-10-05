import sys

n = int(sys.stdin.readline())
s = sys.stdin.readline().rstrip()
cnt = 0

for i in range(n//2):
    if s[i] != s[-1-i]:
        cnt += 1

sys.stdout.write(str(cnt) + '\n');