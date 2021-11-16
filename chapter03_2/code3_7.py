# うまくない組み合わせ全探索

from itertools import product


def check_max_sum(l, T):
    champ = 0
    for i in range(len(T)):
        tmp, index = 0, -1
        for j in T[i]:
            if j == 1:
                tmp += l[index]
            champ = max(tmp, champ)
    return champ


def check_min_sum(l, T):
    champ = 0
    for i in range(len(T)):
        tmp, index = 0, -1
        for j in T[i]:
            index += 1
            if j == 1:
                tmp += l[index]
            champ = min(tmp, champ)
    return champ


def check_between(l, T, a, b):
    champ = 0
    for i in range(len(T)):
        tmp, index = 0, -1
        for j in T[i]:
            index += 1
            if j == 1:
                tmp += l[index]
            if tmp >= a and tmp <= b:
                champ = max(tmp, champ)
    return champ


def main():

    N, M = map(int, input().split())
    # N個の組み合わせ。M個の数を選べる

    Numbers = [list(map(int, (input().split()))) for _ in range(N)]

    a, b = map(int, input().split())

    T = [_ for _ in product((0, 1), repeat=M)]
    # Tは長さM、各要素が整数 0 か 1 のタプルを持つ二重リスト

    for i in Numbers:
        v = check_between(i, T, a, b)
        print(v)


main()
