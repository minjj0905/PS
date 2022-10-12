import sys
from collections import Counter

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
v = int(sys.stdin.readline())

c = Counter(arr)
sys.stdout.write(str(c[v]) + '\n')