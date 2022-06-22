h, m = map(int, input().split())

if m - 45 < 0:
  m = m + 15
  if h:
    h -= 1
  else:
    h = 23
else:
  m -= 45

print(h, m)
