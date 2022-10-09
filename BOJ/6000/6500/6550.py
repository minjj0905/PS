import sys

while 1:
    try:
        s, t = sys.stdin.readline().split()

        for c in t:
            if s[0] == c: s = s[1:]
            if s == "": break
            
        sys.stdout.write('Yes\n' if s == "" else 'No\n')

    except:
        break