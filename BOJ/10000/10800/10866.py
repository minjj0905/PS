import sys

n = int(sys.stdin.readline())
d = []

for i in range(n):
  cmds = list(sys.stdin.readline().split())

  if cmds[0] == "push_front":
    d = [cmds[1]] + d

  elif cmds[0] == "push_back":
    d.append(cmds[1])

  elif cmds[0] == "pop_front":
    print(d.pop(0) if d else -1)
  
  elif cmds[0] == "pop_back":
    print(d.pop() if d else -1)

  elif cmds[0] == "size":
    print(len(d))
  
  elif cmds[0] == "empty":
    print(0 if d else 1)

  elif cmds[0] == "front":
    print(d[0] if d else -1)

  else:
    print(d[-1] if d else -1)