def n_sort(L):
    n = len(L)
    for i in range(n):
        for j in range(n):
            if L[i] < L[j]:
                L[i], L[j] = L[j], L[i]
    return L


L = list(map(int, input().split()))

print(n_sort(L))
