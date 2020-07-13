n = int(input())
sublst = list(map(int, input().split()))
newsublst = []

M = max(sublst)

for sub in sublst:
    newsublst.append(sub/M*100)

print(sum(newsublst)/len(newsublst))