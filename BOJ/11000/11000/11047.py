import sys
input = sys.stdin.readline

n, k = map(int, input().split())
coins = []

for _ in range(n):
    coins.append(int(input()))
coins.reverse()

res = 0

for i in range(n):
    if not k: break

    if k >= coins[i]:
        res += k//coins[i]
        k %= coins[i]

print(res)