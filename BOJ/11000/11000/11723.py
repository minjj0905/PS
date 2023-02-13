import sys
input = sys.stdin.readline

m = int(input())
ar = []

for _ in range(m):
    c = list(input().split())
    cmd = c[0]

    if cmd == 'add':
        if int(c[1]) not in ar:
            ar.append(int(c[1]))
    
    elif cmd == 'remove':
        if int(c[1]) in ar:
            ar.remove(int(c[1]))
    
    elif cmd == 'check':
        if int(c[1]) in ar:
            print(1)
        else: print(0)

    elif cmd == 'toggle':
        if int(c[1]) in ar:
            ar.remove(int(c[1]))
        else:
            ar.append(int(c[1]))

    elif cmd == 'all':
        ar = [i for i in range(1, 21)]
    
    elif cmd == 'empty':
        ar = []
