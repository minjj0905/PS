import sys
n = int(sys.stdin.readline())

q = []

for i in range(n):
  commands = list(sys.stdin.readline().split())
  command = commands[0]

  if command == "push":
    q.append(commands[1])

  elif command == "pop":
    print(q.pop(0) if q else -1)

  elif command == "size":
    print(len(q))

  elif command == "empty":
    print(0 if q else 1)
  
  elif command == "front":
    print(q[0] if q else -1)

  else:
    print(q[-1] if q else -1)