#include <iostream>
#include <vector>

using namespace std;

struct UnionFind
{

    vector<int> par;

    UnionFind(int n) : par(n, -1) {}
    //void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    //bool issame(int x, int y)
    //{
    //    return root(x) == root(y);
    //}
    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    //int size(int x){
    //    return -par[root(x)];
    //}
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> A(V), B(V);
    for (int i = 0; i < V; ++i)
    {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
    }
    int res = 0;
    for (int e = 0; e < E; ++e)
    {
        UnionFind uf(V);
        for (int i = 0; i < E; ++i)
        {
            if (i == e)
                continue;
            uf.merge(A[i], B[i]);
        }
        int num = 0;
        for (int v = 0; v < V; ++v)
        {
            if (uf.root(v) == v)
                ++num;
        }
        if (num > 1)
            ++res;
    }
    cout << res << endl;
}