

def dfs(G, s, seen):
    seen[s] = True

    for i in G:
        if i[0] == s:
            if seen[i[1]]:
                continue
            dfs(G, i[1], seen)


N, M = map(int, input().split())

Graph = [map(int, input().split()) for _ in range(M)]

seen = [False]*N


for i in range(N):
    if seen[i]:
        continue
    dfs(Graph, i, seen)
