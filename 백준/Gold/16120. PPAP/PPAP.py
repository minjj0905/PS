import sys

s = sys.stdin.readline().rstrip()

if s == "P" or s =="PPAP": sys.stdout.write('PPAP\n')
else:
    ppap = []

    for c in s:
        ppap.append(c)
        if len(ppap) >= 4 and "".join(ppap[-4:]) == "PPAP":
            for _ in range(3): ppap.pop()

    sys.stdout.write('PPAP\n' if "".join(ppap) == "PPAP" or "".join(ppap) == "P" else 'NP\n')