import queue


def search(G, s):
    global N
    seen = [False]*N
    todo = queue.Queue()

    seen[s] = True
    todo.put(s)

    while todo:
        v = todo.get()

        for i in G[v]:
            if seen[i]:
                continue
            seen[i] = True
            todo.put(i)


# 頂点数 N、　辺の数 M
N, M = map(int, input().split())

Graph = [map(int, input().split()) for _ in range(M)]

search(Graph, 0)
