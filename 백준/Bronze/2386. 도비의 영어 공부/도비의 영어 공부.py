lst = []

while True:
    w = input().lower()
    if w != '#':
        lst.append(w.split())
    else:
        break

for i in lst:
    cnt = 0
    for j in range(1,len(i)):
        cnt += i[j].count(i[0])
    print(i[0] + " " + str(cnt))