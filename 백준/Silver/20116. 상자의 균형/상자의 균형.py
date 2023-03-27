import sys

n, l = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
arr.reverse()
ans = True
m = arr[0]
for i in range(n-1):
    if i>=1: m = (m*i + arr[i]) / float(i+1)
    if m >= arr[i+1]+l or m <= arr[i+1]-l:
        ans = False
        break

sys.stdout.write("stable\n" if ans else "unstable\n")