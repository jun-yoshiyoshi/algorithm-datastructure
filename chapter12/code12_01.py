def insertion_sort(l):
    n = len(l)
    for i in range(1, n):
        temp = l[i]
        for j in range(i, 0, -1):
            if l[j-1] > temp:
                l[j] = l[j-1]
                l[j-1] = temp  # この位置で挿入ソートと言って問題ないのかよく分からない。
            else:
                break


# n=int(input())
l = list(map(int, input().split()))
insertion_sort(l)

print(l)
