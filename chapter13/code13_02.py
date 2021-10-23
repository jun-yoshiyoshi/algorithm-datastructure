
seen = []


def dfs(G, v):
    global seen[v] = True
    for i in G:
        if seen[i]:
            continue
        dfs(G, i)


N, M = map(int, input().split())

Graph = [map(int, input().split()) for i, j in range(M)]

seen = [False]*N

for i in range(N):
    if seen[i]:
        continue
    dfs(Graph, i)
