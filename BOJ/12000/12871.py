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

s = s*(lcm//len_s)
t = t*(lcm//len_t)

sys.stdout.write('1\n' if s==t else '0\n')