n = int(input())
lst = list(set(list(map(int, input().split()))))
lst.sort()
lst = [str(x) for x in lst]
print(" ".join(lst))