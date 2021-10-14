#include <iostream>

using namespace std;

//単純な根の探索
int root1(int x)
{
    if (par[x] == -1)
        return x;
    else
        return root(par[x]);
}

//経路圧縮による根の探索
int root2(int x)
{
    if (par[x] == -1)
        return x;
    else
        return par[x] = root(par[x]);
}