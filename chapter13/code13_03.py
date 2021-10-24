import queue
N = 0


def BFS(G, N, s):
    dist = [-1]*N
    que = queue.Queue()

    dist[0] = 0
    que.put(0)

    while not que.empty():
        v = que.get()

        for i in G[v]:
            if dist[i] != -1:
                continue
            dist[i] = dist[v]+1
            que.put(i)
    return dist


def main():
    N, M = map(int, input().split())
    Graph = [tuple(map(int, input().split())) for _ in range(M)]

    s = int(input())

    dist = BFS(Graph, N, s)

    for _ in range(N):
        print(dist[_])


main()
