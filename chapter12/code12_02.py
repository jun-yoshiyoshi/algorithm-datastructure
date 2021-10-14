from collections import deque


def merge_sort(L, l, r):
    if r-l != 1:
        mid = (l+r)//2
        merge_sort(L, l, mid)
        merge_sort(L, mid, r)

        buf = deque()
        for i in range(l, mid):
            buf.append(L[i])
        for i in range(r-1, mid-1, -1):
            buf.append(L[i])

        for i in range(l, r):
            if buf[0] <= buf[-1]:
                L[i] = buf.popleft()
            else:
                L[i] = buf.pop()


n = int(input())

L = list(map(int, input().split()))

merge_sort(L, 0, n)

print(L)
