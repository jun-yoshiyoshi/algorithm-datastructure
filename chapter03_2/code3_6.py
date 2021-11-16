
def main():
    n, w = map(int, input().split())
    a = list(map(int, input().split()))

    flag = False

    for bit in range(2**n):
        s = 0
        for i in range(n):
            if bit & 1 << i:
                s += a[i]
        if s == w:
            flag = True
    if flag == True:
        print("Yes")
    else:
        print("No")


main()
