def sol(s):
    p, a = 0, 0
    for i in s:
        if i == 'P':
            if a: p, a = p - 1, 0
            else: p = p + 1
        elif p < 2: return "NP"
        else: a = 1
    if p == 1: return "PPAP"
    return "NP"

s = input()
print(sol(s))