#include <bits/stdc++.h>
using namespace std;
struct DSU
{
    static const int N = 1e5;
    int par[N + 5];
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }
    int getpar(int x)
    {
        return x == par[x] ? x : par[x] = getpar(par[x]);
    }
    bool merge(int x, int y)
    {
        int px = getpar(x);
        int py = getpar(y);
        if (px == py)
            return 0;
        par[px] = py;
        return 1;
    }
};
struct edge
{
    int u, v, w;
    friend bool operator<(edge a, edge b)
    {
        return a.w < b.w;
    }
};
struct Kruskal
{
    DSU dsu;
    int get(vector<edge>& e, int n)//边集 和 结点数
    {
        int ans = 0;
        dsu.init(n);
        sort(e.begin(), e.end());//会排序e数组
        for (auto i : e)
            if (dsu.merge(i.u, i.v))
                ans += i.w;
        return ans;
    }
};
int main()
{
    return 0;
}