import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
arr.reverse()

max_value = arr[0]
profit = 0
for a in arr[1:]:
    if a > max_value:
        max_value = a
    if max_value - a > profit:
        profit = max_value - a

sys.stdout.write(str(profit) + '\n')