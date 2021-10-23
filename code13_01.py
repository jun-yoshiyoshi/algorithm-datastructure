import queue

N = int, input()
G = [map(int, input().split()) for i in range(N)]
s = map(int, input().split())


def search(G, s):
    seen = [False]*N
    todo = queue.queue()

    seen[s] = True
    todo.put(s)

    while todo:
        v = todo[0]
        todo.get()

        for i in G:
            if seen[i]:
                continue
            seen[i] = True
            todo.put(i)


# 頂点数 N、　辺の数 M
N, M = map(int, input().split())

Graph = [map(int, input().split()) for i, j in range(M)]

search(G, 0)
