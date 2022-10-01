import sys

n = int(sys.stdin.readline())
l, r = 100, 100

for _ in range(n):
  l_score, r_score = map(int, sys.stdin.readline().split())
  if(l_score == r_score): continue
  elif(l_score > r_score):
    r -= l_score
  else:
    l -= r_score

sys.stdout.write(str(l) + '\n')
sys.stdout.write(str(r) + '\n')
