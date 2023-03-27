import sys

def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)

s = sys.stdin.readline().rstrip()
t = sys.stdin.readline().rstrip()

len_s = len(s)
len_t = len(t)

g = gcd(len_s, len_t)
lcm = len_s * len_t // g

ans = 1
for i in range(lcm):
    if s[i%len_s] != t[i%len_t]: ans = 0

sys.stdout.write(str(ans) + '\n')