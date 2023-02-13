import sys
input = sys.stdin.readline

dp = [[0 for _ in range(31)] for _ in range(31)]

for w in range(1, 31):
    dp[0][w] = 1

for h in range(1, 31):
    for w in range(1, 31):
        if w >= h:
            dp[h][w] = dp[h-1][w] + dp[h][w-1]


while 1:
    n = int(input())
    if not n: break

    print(dp[n][n])    
