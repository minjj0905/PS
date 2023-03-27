n = int(input())
f = int(input())

w = str(n)

w = w[:len(w)-2]+'00'

while True:
    if int(w)%f==0:
        print(w[len(w)-2:])
        break
    else:
        w = str(int(w)+1)