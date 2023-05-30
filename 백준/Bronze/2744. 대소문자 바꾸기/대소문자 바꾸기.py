s = input()
ans = ''
for c in s:
    ans += c.upper() if c.islower() else c.lower()
print(ans)
