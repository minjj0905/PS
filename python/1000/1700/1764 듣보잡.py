n, m = map(int, input().split())

notheard = []
notsaw = []

dbz = []

for _ in range(n):
    notheard.append(str(input()))
for _ in range(m):
    notsaw.append(str(input()))

dbz = list(set(notheard) & set(notsaw))

print(len(dbz))
for x in sorted(dbz):
    print(x)