import sys
n = int(sys.stdin.readline())
arr = []

for i in range(n):
  arr.append(int(sys.stdin.readline()))
arr.sort()
print(round(sum(arr)/n))
print(arr[n//2])

dic = {}
for a in arr:
  if a in dic:
    dic[a] += 1
  else:
    dic[a] = 1

max_key = max(dic, key=dic.get)
max_value = dic[max_key]
del dic[max_key]

if max_value in dic.values():
  for k, v in dic.items(): 
    if v == max_value:
      print(k)
      break
else:
   print(max_key)

print(abs(arr[0] - arr[-1]))
