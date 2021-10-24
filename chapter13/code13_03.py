import queue


def BFS(G, N):
    dist = [-1]*N
    dist[0] = 0
    # 始点０からの距離を保存

    que = queue.Queue()
    que.put(0)
    # 移動距離をチェックした点を記録

    while not que.empty():
        v = que.get()

        for i in G:
            # i[0]は出発点であり、i[1]は移動先になる点
            if dist[i[1]] == -1:
                dist[i[1]] = dist[i[0]]+1
                que.put(i[1])
    return dist


def main():
    N, M = map(int, input().split())

    Graph = [tuple(map(int, input().split())) for _ in range(M)]

    Graph = Graph+[(j, k) for (k, j) in Graph]
    # for i in Graph:
    #     (j, k) = i[1], i[0]
    #     Graph_b.append((j, k))

    dist = BFS(Graph, N)  # 引数はグラフデータと頂点の数　始点は０
    print(dist)


main()
