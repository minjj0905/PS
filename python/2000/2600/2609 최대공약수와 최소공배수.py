n, m = map(int, input().split())

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b !=0:
        a, b = b, a%b
    return a

print(gcd(n, m))
print(n*m//gcd(n,m))