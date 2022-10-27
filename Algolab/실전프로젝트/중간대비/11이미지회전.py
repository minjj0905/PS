import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n, a = map(int, sys.stdin.readline().split())
    image = []

    for _ in range(n):
        image.append(sys.stdin.readline().rstrip())

    aa = {-270: 90, -180: 180, -90: -90, 0: 0, 90:90, 180:180, 270:-90}
    a = aa[a]

    if a == -90:
        for i in range(n-1, -1, -1):
            for j in range(n):
                sys.stdout.write(image[j][i])
            sys.stdout.write('\n')

    elif a == 90:
        for i in range(n):
            for j in range(n-1, -1, -1):
                sys.stdout.write(image[j][i])
            sys.stdout.write('\n')

    elif a == 180:
        for i in range(n-1, -1, -1):
            for j in range(n-1, -1, -1):
                sys.stdout.write(image[i][j])
            sys.stdout.write('\n')

    else:
        for line in image:
            sys.stdout.write(line + '\n')