while True:
    n = input()
    if int(n) == 0:
        break
    else:
        for i in range(len(n)//2):
            if n[i] != n[len(n)-i-1]:
                print("no")
                break

        else:
            print("yes")