import sys
from collections import deque

def calc(q):
  value = 0
  signs = ["*", "+", "-"]

  for sign in signs:
    cur = q.popleft()
    
  return value;

tc = int(sys.stdin.readline())

for _ in range(tc):
  l = int(sys.stdin.readline())
  q = deque(sys.stdin.readline())

  
  arr = []

  while(1):
    cur = q.popleft()
    # if cur == "(":
      