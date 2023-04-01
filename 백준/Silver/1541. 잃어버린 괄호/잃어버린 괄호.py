# 1541 잃어버린 괄호

import sys

s = sys.stdin.readline().rstrip()
arr = s.split("-")
for i in range(len(arr)):
    lst = arr[i].split('+')
    for j in range(len(lst)): lst[j] = lst[j].lstrip("0")
    arr[i] = eval("+".join(lst))

ans = arr[0]

for a in arr[1:]:
    ans -= a

sys.stdout.write(str(ans) + '\n')