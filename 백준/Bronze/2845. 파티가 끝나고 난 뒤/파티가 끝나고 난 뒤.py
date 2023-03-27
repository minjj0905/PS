peoples, size = map(int, input().split())
lst = list(map(int, input().split()))
answer = []
for i in lst:
    answer.append(str(i - peoples*size))
print(" ".join(answer))