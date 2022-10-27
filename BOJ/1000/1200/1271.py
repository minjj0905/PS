import sys

n, m = map(int, sys.stdin.readline().split())
sys.stdout.write(str(n//m) + ' ' + str(n%m) + '\n')