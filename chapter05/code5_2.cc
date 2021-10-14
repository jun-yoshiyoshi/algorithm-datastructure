//緩和処理を実現するための関数
template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}