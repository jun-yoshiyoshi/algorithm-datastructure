n = int(input())

L = list(map(int, input().split()))

l = sorted(L)

index=[l.index(L[i]) for i in range(n)]

print(index)
    
