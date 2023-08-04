import sys
input = sys.stdin.readline

k, m, n = map(int, input().split())
manual = ''.join(input().split())
user = ''.join(input().split())

if manual in user:
    print("secret")
else:
    print("normal")
