import sys

n = int(sys.stdin.readline())
s = []

for i in range(n):
  cmds = list(sys.stdin.readline().split())
  cmd = cmds[0]

  if cmd == "push":
    s.append(cmds[1])
  
  elif cmd == "pop":
    print(s.pop() if s else "-1")
  
  elif cmd == "size":
    print(len(s))

  elif cmd == "empty":
    print(0 if s else 1)
  
  else:
    print(s[-1] if s else -1)
