import sys
input = sys.stdin.readline


n, m = map(int, input().split())
arr = list(map(int, input().split()))

prefix_sum = [0 for _ in range(n)]
prefix_sum[0] = arr[0]

for i in range(1, n):
    prefix_sum[i] = prefix_sum[i-1] + arr[i]

for i in range(m):
    i, j = map(int, input().split())
    print(prefix_sum[j-1] - prefix_sum[i-1] + arr[i-1])
