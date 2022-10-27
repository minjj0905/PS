import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    d = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    
    arr.reverse()
    
    res = 0
    max_value = arr[0]
    for a in arr:
        if a > max_value: max_value = a
        else: res += max_value - a
    
    sys.stdout.write(str(res) + '\n')