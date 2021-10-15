def quick_sort(L, l, r):
    if r-l > 1:
        pivot_idx = (l+r)//2
        pivot = L[pivot_idx]
        L[pivot_idx], L[r-1] = L[r-1], L[pivot_idx]

        i = l
        for j in range(l, r-1):
            if L[j] < pivot:
                L[i], L[j] = L[j], L[i]
                i += 1
        L[i], L[r-1] = L[r-1], L[i]
        quick_sort(L, l, i)
        quick_sort(L, i+1, r)


n = int(input())

L = list(map(int, input().split()))

quick_sort(L, 0, n)

print(L)
