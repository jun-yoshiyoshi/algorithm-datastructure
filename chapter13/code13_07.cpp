#include <vector>
using namespace std;

using Graph = vector<vector<int>>;

void dfs(const Graph &G, int v, int p = -1)
{
    for (auto c : G[v])
    {
        if (c == p)
            continue;

        dfs(G, c, v);
    }
}
