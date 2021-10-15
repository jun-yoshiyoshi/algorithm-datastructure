def heap(L, i, N):
    child_1 = i*2+1
    if child_1 < N:
        if child_1+1 < N and L[child_1+1] > L[child_1]:
            child_1 += 1
        if L[child_1] > L[i]:
            L[i], L[child_1] = L[child_1], L[i]

        heap(L, child_1, N)


def heap_sort(L):
    n = len(L)

    for i in range(n//2-1, -1, -1):
        heap(L, i, n)

    for i in range(n-1, 0, -1):
        L[0], L[i] = L[i], L[0]
        heap(L, 0, i)


n = int(input())

L = list(map(int, input().split()))

heap_sort(L)

print(L)
