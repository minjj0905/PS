import sys
from collections import Counter

n = int(sys.stdin.readline())
s = sys.stdin.readline().rstrip()

while(1):
    c = Counter(s)
    if c["s"] != c["t"]:
        s = s[1:]
    else:
        break

sys.stdout.write(s + '\n')
 