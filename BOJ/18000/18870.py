import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
set_arr = sorted(list(set(arr)))

dic = {set_arr[i] : i for i in range(len(set_arr))}

for a in arr:
    sys.stdout.write(str(dic[a]) + ' ')

sys.stdout.write('\n')