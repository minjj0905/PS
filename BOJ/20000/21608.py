import sys
input = sys.stdin.readline

n = int(input())
arr = []
for _ in range(n*n):
    arr.append(list(map(int, input().split())))

table = [[0 for _ in range(n)] for _ in range(n)]
table[(n-1)//2][(n-1)//2] = arr[0][0]

likes = [0 for _ in range(n*n+1)]
likes[arr[0][0]] = arr[0][1:]

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

for stud in arr[1:]:
    seats = [n, n]
    like = 0
    empty = 0

    stud_num = stud[0]
    like_arr = stud[1:]
    likes[stud_num] = like_arr

    for y in range(n):
        for x in range(n):
            if table[y][x] != 0: continue
            cur_like = 0
            cur_empty = 0

            for d in range(4):
                adj_y = y + dy[d]
                adj_x = x + dx[d]
                if 0 <= adj_y < n and 0 <= adj_x < n:
                    if table[adj_y][adj_x] in like_arr:
                        cur_like += 1
                    elif table[adj_y][adj_x] == 0:
                        cur_empty += 1
            
            if cur_like > like:
                like = cur_like
                empty = cur_empty
                seats = [y, x]

            elif cur_like == like:
                if cur_empty > empty:
                    empty = cur_empty
                    seats = [y, x]
                    
                elif cur_empty == empty:
                    if y < seats[0]:
                        seats = [y, x]
                    elif y == seats[0] and x < seats[1]:
                        seats = [y, x]
    table[seats[0]][seats[1]] = stud_num

satis = 0

for i in range(n):
    for j in range(n):
        cur = table[i][j]
        like_arr = likes[cur]
        cnt = 0

        for d in range(4):
            adj_y = i + dy[d]
            adj_x = j + dx[d]

            if 0 <= adj_y < n and 0 <= adj_x < n:
                if table[adj_y][adj_x] in like_arr:
                    cnt += 1
        
        satis += 10 ** (cnt-1) if cnt else 0

print(satis)


"""
3
1 6 7 8 9
2 6 7 8 9
3 6 7 8 9
4 6 7 8 9
5 6 7 8 9
6 1 2 3 4
7 1 2 3 4
8 1 2 3 4
9 1 2 3 4
"""