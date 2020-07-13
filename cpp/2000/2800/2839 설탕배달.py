n = int(input())
three, five = 0, 0

while (n%5 != 0 and n >= 0):
    n -= 3
    three += 1

if (n%5 == 0 and n>=0):
    five = n//5
    print(three+five)
else:
    print(-1)