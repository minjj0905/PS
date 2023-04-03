import sys
input = sys.stdin.readline

heap = [0]
n = int(input())

for _ in range(n):
    x = int(input())
    if not x:
        if len(heap) == 1:
            print(0)
        else:
            print(heap[1])
            heap[1] = heap[len(heap) - 1]
            del heap[len(heap) - 1]

            if len(heap) == 3:
                if heap[1] > heap[2]:
                    heap[1], heap[2] = heap[2], heap[1]
            elif len(heap) > 3:
                idx = 1
                child_l = 2
                child_r = 3
                child = 0

                if heap[child_l] < heap[child_r]:
                    child = child_l
                else:
                    child = child_r
                while idx <= len(heap) and child <= len(heap) and heap[child] < heap[idx]:
                    heap[child], heap[idx] = heap[idx], heap[child]
                    child_l = child * 2
                    child_r = child * 2 + 1
                    idx = child
                    if child_r >= len(heap):
                        if child_l >= len(heap):
                            break
                        else:
                            child = child_l
                    elif (heap[child_l] < heap[child_r]):
                        child = child_l
                    else:
                        child = child_r

    else:
        heap.append(x)
        idx = len(heap) - 1

        if idx <= 1:
            continue

        parent = idx // 2

        while heap[parent] > heap[idx]:
            heap[idx], heap[parent] = heap[parent], heap[idx]
            idx = parent
            parent = idx // 2
