import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    
    n = int(sys.stdin.readline())
    arr = [{'length': 0, 'elements': 0} for _ in range(100)]
    
    cnt = 0
    
    for _ in range(n):
        a, c = map(int, sys.stdin.readline().split())
    
        if arr[a]['length'] >= arr[a]['elements'] + c:
            arr[a]['elements'] += c
    
        else:
            elements = arr[a]['elements'] + c
    
            r = len(str(bin(elements))[2:])
            arr[a]['length'] = 2**r
    
            cnt += arr[a]['elements']
    
            arr[a]['elements'] = elements
    
    sys.stdout.write(str(cnt) + '\n')