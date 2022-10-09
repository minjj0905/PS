import sys
n = int(sys.stdin.readline())

for _ in range(n):
    s = sys.stdin.readline()
    depth = 0
    stack = []

    for c in s:
        if c == "]":
            depth = max(depth, len(stack))
            stack.pop()
        else:
            stack.append('[')
    
    sys.stdout.write(str(2**depth) + '\n')


