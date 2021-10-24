

seen = []


def dfs(G, s, seen):
    seen[s] = True

    for i in G:
        if i[0] == s:
            if seen[i[1]]:
                continue
            dfs(G, i[1], seen)


def main():
    N, M, s, t = map(int, input().split())

    Graph = [tuple(map(int, input().split())) for _ in range(M)]

    seen = [False]*N
    dfs(Graph, s, seen)

    if seen[t]:
        print("yes")
    else:
        print("no")


main()
