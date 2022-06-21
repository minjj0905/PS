n = int(input())
print(1) if n % 4 == 0 and (n % 400 == 0 or n % 100 != 0) else print(0)
