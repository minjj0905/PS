n, r, c = map(int, input().split())

def solution(n, r, c):
    if n == 1:
        if r == 0:
            if c == 0: return 0
            else: return 1
        else:
            if c == 0: return 2
            else: return 3
    
    if r >= 2**(n-1):
        half = 2 ** (2*n - 1)
        if c >= 2**(n-1):
            return half + 2 ** (2*n - 2) + solution(n-1, r-(2**(n-1)), c-(2**(n-1)))
        else:
            return half + solution(n-1, r-(2**(n-1)), c)
    else:
        if c >= 2**(n-1):
            return 2 ** (2*n - 2) + solution(n-1, r, c-(2**(n-1)))
        else:
            return solution(n-1, r, c)

print(solution(n, r, c))