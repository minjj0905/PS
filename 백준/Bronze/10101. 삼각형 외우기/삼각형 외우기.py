arr = []
for _ in range(3):
    arr.append(int(input()))

arr.sort()
s = sum(arr)

if arr[0] == arr[2] == 60:
    print("Equilateral")
elif s == 180 and (arr[0] == arr[1] or arr[1] == arr[2]):
    print("Isosceles")
elif s == 180:
    print("Scalene")
else:
    print("Error")