import heapq as hq

N, k = map(int, input().split())

S = list(map(int, input().split()))
S = list(map(lambda x: x*(-1), S))  # -1を乗じてヒープで最大値を出力できるようにする

low_heap = []
for i in range(N):
    if(i < k):
        hq.heappush(low_heap, S[i])
    else:
        M = low_heap[0]*(-1)
        if(S[i]*(-1) >= M):  # S[i]もMも負であることに注意
            pass
        else:
            hq.heappush(low_heap, S[i])
            hq.heappop(low_heap)  # 最大値の削除

    M = low_heap[0]*(-1)
    print("{}個が挿入されたとき{}番目に小さい数は{}".format(i+1, k, M))
