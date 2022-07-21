import sys

tc = int(sys.stdin.readline())

for i in range(tc):
  arr = []
  s = sys.stdin.readline().rstrip()
  
  if s[0] == ")":
    print("NO")
    continue    
  
  else: 
    arr.append(s[0])

  for i in range(1, len(s)):
    if arr and arr[-1] != s[i]:
      arr.pop()

    elif not arr and s[i] == ")" :
      arr.append("NO")
      break

    else:
      arr.append(s[i])

  print("NO" if arr else "YES")