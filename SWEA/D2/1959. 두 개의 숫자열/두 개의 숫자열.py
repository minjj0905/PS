t = int(input())
for tc in range(t):
    n, m = map(int, input().split())
    a_arr = list(map(int, input().split()))
    b_arr = list(map(int, input().split()))
 
    if n > m:
        n, m = m, n
        a_arr, b_arr = b_arr, a_arr
 
    ans = -0x7fffffff
    for i in range(0, m-n + 1):
        res = 0
        for j in range(n):
            res += a_arr[j] * b_arr[i+j]
         
        ans = max(ans, res)
     
    print(f"#{tc + 1} {ans}")