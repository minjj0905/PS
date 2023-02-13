import sys

cash = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

j_cash, s_cash = cash, cash
j_stock, s_stock = 0, 0

prev = []

for p in arr[:-1]:
    if j_cash >= p:
        while j_cash >= p:
            j_cash -= p
            j_stock += 1

    if len(prev) < 3:
        prev.append(p)
    else:
        if prev[0] > prev[1] > prev[2]:
            while s_cash >= p:
                s_cash -= p
                s_stock += 1
            
        elif prev[0] < prev[1] < prev[2]:
            while s_stock:
                s_cash += p
                s_stock -= 1
        prev.pop(0)
        prev.append(p)

s, j = 0, 0
j = j_cash + arr[-1]*j_stock
s = s_cash + arr[-1]*s_stock

if j>s: print("BNP")
elif s>j: print("TIMING")
else: print("SAMESAME")