from math import comb

n, m, k = map(int, input().split())
res = 0

for i in range(k, m+1):
    res += comb(m, i) * comb(n-m, m-i)

print(res / comb(n,m))