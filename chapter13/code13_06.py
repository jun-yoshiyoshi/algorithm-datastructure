def toporogical_sort(G, v, N, seen, order):
    seen[v] = True
    for i in G:
        if i[0] == v:
            if seen[i[1]]:
                continue
            toporogical_sort(G, i[1], N, seen, order)
    order.append(v)


def main():

    N, M = map(int, input().split())

    Graph = [tuple(map(int, input().split())) for _ in range(M)]

    for i in range(N):
        seen, order = [False]*N, []
        for i in range(N):
            if seen[i] == True:
                continue
            toporogical_sort(Graph, i, N, seen, order)

    order.reverse()

    print(order)


main()

# 8 12
# 0 5
# 1 3
# 1 6
# 2 5
# 2 7
# 3 0
# 3 7
# 4 1
# 4 2
# 4 6
# 6 7
# 7 0
