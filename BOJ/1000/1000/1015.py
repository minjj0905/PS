import sys

n = int(sys.stdin.readline())
a = list(map(int, sys.stdin.readline().split()))

sorted_a = sorted(a)
p = []

for i in a:
  p.append(str(sorted_a.index(i)))
  sorted_a[sorted_a.index(i)] = -1

print(" ".join(p))