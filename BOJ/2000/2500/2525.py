h, m = map(int, input().split())
m += int(input())

print((h+m//60)%24, m%60)