t = int(input())
for _ in range(t):
    s = input().split();
    ans = []
    for word in s:
        ans.append(word[::-1])
    print(" ".join(ans))