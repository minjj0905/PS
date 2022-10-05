import sys
from collections import Counter

mbti = sys.stdin.readline()
n = int(sys.stdin.readline())
arr = []
for _ in range(n):
    arr.append(sys.stdin.readline())

print(arr)

sys.stdout.write(str(Counter(arr)[mbti])+'\n')