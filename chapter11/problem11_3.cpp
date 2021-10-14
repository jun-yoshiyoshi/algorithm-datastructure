#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct UnionFind
{
    vector<int> par;

    UnionFind() {}
    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }
    bool merge(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x == y)
            return false;

        if (par[y] < par[x])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x)
    {
        return par[root(x)];
    }
};

int main()
{
    int N, K, L;
    cin >> N >> K >> L;

    UnionFind road(N), train(N);
    for (int i = 0; i < K; ++i)
    {
        int p, q;
        cin >> p >> q;
        --p, --q;
        road.merge(p, q);
    }
    for (int i = 0; i < L; ++i)
    {
        int r, s;
        cin >> r >> s;
        --r, --s;
        train.merge(r, s);
    }
    map<pair<int, int>, int> nums;
    for (int i = 0; i < N; ++i)
    {
        int root_road = road.root(i);
        int root_train = train.root(i);
        nums[make_pair(root_road, root_train)]++;
    }
    for (int i = 0; i < N; ++i)
    {
        int root_road = road.root(i);
        int root_train = train.root(i);
        cout << nums[make_pair(root_road, root_train)] << " ";
    }
    cout << endl;
}