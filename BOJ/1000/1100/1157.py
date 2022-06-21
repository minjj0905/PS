s = input()
s = s.upper()

arr = {}
for c in s:
    if c in arr:
        arr[c] += 1
    else:
        arr[c] = 1

max_key = max(arr, key=arr.get)
m = arr[max_key]
del arr[max_key]

print("?") if m in arr.values() else print(max_key)