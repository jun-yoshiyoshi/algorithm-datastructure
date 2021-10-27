

def dfs(G, v, color, cur=0):
    color[v] = cur

    for i in G:
        if i[0] == v:
            if color[i[1]] != -1:
                if color[i[1]] == cur:
                    return False
                continue
            if dfs(G, i[1], 1-cur) == False:
                return False
    return True


def main():
    N, M = map(int, input().split())

    Graph = [tuple(map(int, input().split())) for _ in range(M)]

    Graph = Graph+[(j, k) for (k, j) in Graph]

    color = [-1]*N
    # -1は未確定0で白、1で黒
    is_bipartite = True

    for i in range(N):
        if color[i] != -1:
            continue
        if dfs(Graph, i, color) == False:
            is_bipartite = False

    if is_bipartite == True:
        print("yes")
    else:
        print("no")


main()
