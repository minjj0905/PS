t = int(input())

for i in range(t):
  n, m, a, b = map(int, input().split())
  if a > b:
    a, b = b, a

  info = []
  gram = 999999999

  for i in range(m):
    o, d, c = map(int, input().split())
    if o > d: 
      o, d = d, o

    info.append([o, d, c])

  info.sort(key= lambda x: (x[0], x[1]))
  start = list(filter(lambda x: x[0]==a or x[0]==b, info))
  
  current = a
  idx = 0

  while(True):
    # 직통
    if start[idx][0]== a and start[idx][1] == b:
      print(start[idx][2])
      break

    # 거쳐가는 경우
    else:
      if start[idx][0] == current and start[idx][1] == b:
        gram = min(gram, c)
        print(gram)
        break

      elif start[idx][0] == current:
        current = start[idx][0]
        gram = min(gram, c)
      
    idx += 1
