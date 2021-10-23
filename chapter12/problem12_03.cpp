#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Heap_Max
{
    vector<int> heap;
    Heap_Max() {}

    void push(int x)
    {
        heap.push_back(x);
        int i = (int)heap.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] >= x)
                break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }
    int top()
    {
        if (!heap.empty())
            return heap[0];
        else
            return -1;
    }
    void pop()
    {
        if (heap.empty())
            return;
        int x = heap.back();
        heap.pop_back();
        int i = 0;
        while (i * 2 + 1 < (int)heap.size())
        {
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size() && heap[child2] > heap[child1])
            {
                child1 = child2;
            }
            if (heap[child1] <= x)
                break;
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x;
    }
};
struct Heap_Min
{
    vector<int> heap;
    Heap_Min() {}

    void push(int x)
    {
        heap.push_back(x);
        int i = (int)heap.size() - 1;
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] <= x)
                break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }
    int top() //最小値を取得
    {
        if (!heap.empty())
            return heap[0];
        else
            return -1;
    }
    void pop() //最小値を削除
    {
        if (heap.empty())
            return;
        int x = heap.back();
        heap.pop_back();
        int i = 0;
        while (i * 2 + 1 < (int)heap.size())
        {
            int child1 = i * 2 + 1, child2 = i * 2 + 2;
            if (child2 < (int)heap.size() && heap[child2] < heap[child1])
            {
                child1 = child2;
            }
            if (heap[child1] >= x)
                break;
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x;
    }
};

int main()
{
    int N, k;
    cin >> N >> k;

    vector<int> S(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
    }

    Heap_Max low;
    Heap_Min high;
    for (int i = 0; i < N; ++i)
    {
        if (i < k)
        {
            low.push(S[i]);
        }
        else
        {
            int M = low.top(); //Mはlowの最大値であり、k番目に小さい数
            if (S[i] >= M)
            {
                high.push(S[i]);
            }
            else
            {
                low.push(S[i]);
                low.pop();
            }
        }
        cout << i + 1 << ":" << low.top() << endl;
    }
}
