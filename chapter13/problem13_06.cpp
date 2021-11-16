#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen, finished;

int pos = -1;
stack<int> hist;

void dfs(const Graph &G, int v, int p)
{
    seen[v] = true;
    hist.push(v);
    for (auto x : G[v])
    {
        if (x == p)
            continue;
        if (finished[x])
            continue;
        if (seen[x] && !finished[x])
        {
            pos = x;
            return;
        }
        dfs(G, x, v);
        if (pos != -1)
            return;
    }
    hist.pop();
    finished[v] = true;
}

int main()
{
    //頂点数 N　辺の数 M
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        //インデックスに揃える
        G[a].push_back(b);
    }
    seen.assign(N, false), finished.assign(N, false);
    pos = -1;
    dfs(G, 0, -1);
    set<int> cycle;
    while (!hist.empty())
    {
        int t = hist.top();
        cycle.insert(t);
        hist.pop();
        if (t == pos)
            break;
    }
}
