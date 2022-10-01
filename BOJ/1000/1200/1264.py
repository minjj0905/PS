from collections import Counter

strs = []
while(1):
  s = input()
  if (s=="#"): break
  strs.append(s.lower())

for s in strs:
  c = Counter(s)
  print(c['a'] + c['e']+ c['i'] + c['o'] + c['u'])