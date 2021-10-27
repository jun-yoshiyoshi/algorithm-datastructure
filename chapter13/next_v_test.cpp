#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using Graph = vector<vector<int>>;

void pri(const Graph &G, int v)
{
    for (auto next_v : G[v])
        cout << v << ":" << next_v << endl;
}

Graph Matrix = {{0, 100}, {1, 10}, {2, 20, 200, 2000}, {3, 30}, {22, 40}, {20, 50}};

int main()
{
    pri(Matrix, 2);
}
