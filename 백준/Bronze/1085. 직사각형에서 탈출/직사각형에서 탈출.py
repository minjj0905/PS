lst = list(map(int, input().split()))
lst[2] = lst[2] - lst[0]
lst[3] = lst[3] - lst[1]

print(min(lst))