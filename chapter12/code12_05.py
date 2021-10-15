MAX = 10


def bucket_sort(L):
    n = len(L)

    num = [0]*MAX
    for i in L:
        num[i] += 1

    s = [0]*MAX
    for v in range(1, MAX):
        s[v] = s[v-1]+num[v]

    L2 = [None]*n
    for i in range(n-1, -1, -1):
        L2[s[L[i]]-1] = L[i]

    return L2


n = int(input())

L = list(map(int, input().split()))

L = bucket_sort(L)

print(L)
