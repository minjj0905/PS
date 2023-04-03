import sys
input = sys.stdin.readline

num = int(input())


def hanoi(n, start, mid, end):
    if n == 1:
        print(str(start) + ' ' + str(end))
        return

    hanoi(n-1, start, end, mid)
    print(str(start) + ' ' + str(end))
    hanoi(n-1, mid, start, end)


print(2**num-1)
if num <= 20:
    hanoi(num, 1, 2, 3)
