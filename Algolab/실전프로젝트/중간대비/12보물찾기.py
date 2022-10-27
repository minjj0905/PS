import sys

tc = int(sys.stdin.readline())

dir = {'F' : {'F' : 'F', 'R' : 'R', 'L' : 'L', 'B' : 'B'},
    'R': {'F': 'R', 'R': 'B', 'L': 'F', 'B': 'L'},
    'L': {'F': 'L', 'R': 'F', 'L': 'B', 'B': 'R'},
    'B': {'F': 'B', 'R': 'L', 'L': 'R', 'B': 'F'}}

for _ in range(tc):
    n = int(sys.stdin.readline())
    prev = 'B'
    visited = [[[] for _ in range(n)] for _ in range(n)]

    map = []
    for _ in range(n):
        map.append(sys.stdin.readline().split())
    
    x, y = 0, 0
    while True:
        n_dir = dir[prev][map[y][x][0]]

        if n_dir in visited[y][x]:
            sys.stdout.write(str(y) + ' ' + str(x) + '\n')
            break
        else:
            visited[y][x].append(n_dir)

            distance = int(map[y][x][1])
            if n_dir == 'F': y += distance
            elif n_dir == 'B': y -= distance
            elif n_dir == 'R': x += distance
            else: x -= distance
            prev = n_dir


