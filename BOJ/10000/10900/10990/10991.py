n=int(input())

for i in range(1, n+1):
    if i==1:
        print(" "*(n-1) + "*")
    else:
        print(" "*(n-i)  + "* "*i)