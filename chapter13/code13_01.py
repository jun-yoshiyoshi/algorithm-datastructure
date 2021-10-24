import queue


def search(G, N, s):
    seen = [False]*N
    todo = queue.Queue()

    seen[s] = True
    todo.put(s)

    while not todo.empty():
        v = todo.get()
        for i in G[v]:
            if seen[i]:
                continue
            seen[i] = True
            todo.put(i)


def main():
    # 頂点数 N、　辺の数 M
    N, M = map(int, input().split())

    Graph = [tuple(map(int, input().split())) for _ in range(M)]

    search(Graph, N, 0)


main()
