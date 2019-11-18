n = int(input())
words = []
for _ in range(n):
    words.append(str(input()))
notgroupword = 0

for word in words:
    appeared = []
    if len(word) == 1:
        continue
    for x in word:
        if x not in appeared:
            appeared.append(x)
        elif appeared[-1] == x:
            pass
        else:
            notgroupword += 1
            break

print(n-notgroupword)