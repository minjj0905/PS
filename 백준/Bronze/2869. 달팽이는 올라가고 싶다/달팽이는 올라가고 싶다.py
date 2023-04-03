import sys
import math
input = sys.stdin.readline

a, b, v = map(int, input().split())
diff = a - b
v -= a

print(math.ceil(v/diff) + 1)
