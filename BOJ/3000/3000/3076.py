import sys

r, c = map(int, sys.stdin.readline().split())
a, b = map(int, sys.stdin.readline().split())


for i in range(r//2):
    s = ""
    for i in range(c):
        if i%2: s += "."*b
        else: s += "X"*b
        
    for _ in range(a): sys.stdout.write(s + '\n')

    s = ""
    for i in range(c):
        if i%2: s += "X"*b
        else: s += "."*b
    for _ in range(a): sys.stdout.write(s + '\n')

if r%2:
    s = ""
    for i in range(c):
        if i%2: s += "."*b
        else: s += "X"*b
    for _ in range(a): sys.stdout.write(s + '\n')
