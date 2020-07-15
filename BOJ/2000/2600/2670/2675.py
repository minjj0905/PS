t = int(input())
for c in range(t):
    n, s = input().split()
    n = int(n)
    ans = ""

    for x in s:
        for i in range(n):
            ans = ans + x

    print(ans)