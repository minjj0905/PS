import sys
input = sys.stdin.readline

n = int(input())
sum = 0
xor = 0

for _ in range(n):
    cmd = list(map(int, input().split(' ')));
    if cmd[0] == 1:
        sum += cmd[1]
        xor ^= cmd[1]
    elif cmd[0] == 2:
        sum -= cmd[1]
        xor ^= cmd[1]
    elif cmd[0] == 3:
        print(sum)
    else:
        print(xor)
