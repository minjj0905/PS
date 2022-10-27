import sys

tc = int(sys.stdin.readline())
for _ in range(tc):
    n = int(sys.stdin.readline())
    arr = [{"length": 0, "elements": 0} for _ in range(100)]

    cnt = 0

    for _ in range(n):
        a, c = map(int, sys.stdin.readline().split())

        # 길비보다 짧으면 element 더하기
        if arr[a]["length"] >= arr[a]["elements"] + c:
            arr[a]["elements"] += c

        else:
            elements = arr[a]["elements"] + c

            # 배열 크기 늘리기
            r = len(str(bin(elements))[2:])
            arr[a]["length"] = 2**r

            # 복사 카운트 증가
            cnt += arr[a]["elements"]
            
            # 원소 갯수 바꾸기
            arr[a]["elements"] = elements
    
    sys.stdout.write(str(cnt) + '\n')