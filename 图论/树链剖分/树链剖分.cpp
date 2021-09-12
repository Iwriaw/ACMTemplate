#include <bits/stdc++.h>
using namespace std;
struct ChainSplit
{
    const static int N = 1e5; //node[1, N]
    int par[N + 5], dep[N + 5], siz[N + 5], son[N + 5], top[N + 5], dfn[N + 5];
    int dfsc;
    void split(vector<int> g[], int n)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = 0;
            dep[i] = 0;
            siz[i] = 0;
            son[i] = 0;
            top[i] = 0;
            dfn[i] = 0;
        }
        dfsc = 0;
        dfs1(1, 0, g);
        dfs2(1, 0, 1, g);
    }
    void dfs1(int now, int pre, vector<int> g[])
    {
        son[now] = 0;
        siz[now] = 1;
        par[now] = pre;
        dep[now] = dep[pre] + 1;
        for (int i : g[now])
            if (i != pre)
            {
                dfs1(i, now, g);
                siz[now] += siz[i];
                if (siz[i] > siz[son[now]])
                    son[now] = i;
            }
    }
    void dfs2(int now, int pre, int tp, vector<int> g[])
    {
        top[now] = tp;
        dfn[now] = ++dfsc;
        if (son[now])
            dfs2(son[now], now, tp, g);
        for (int i : g[now])
            if (i != pre && i != son[now])
                dfs2(i, now, i, g);
    }
    void query(int x, int y)
    {
        int tx = top[x];
        int ty = top[y];
        while (tx != ty)
        {
            if (dep[tx] >= dep[ty])
            {
                //询问[dfn[tx], dfn[x]]
                x = par[tx];
                tx = top[x];
            }
            else
            {
                //询问[dfn[ty], dfn[y]]
                y = par[ty];
                ty = top[y];
            }
        }
        if (dep[x] >= dep[y])
        {
            //询问[dfn[y], dfn[x]]
        }
        else
        {
            //询问[dfn[x], dfn[y]]
        }
    }
};
int main()
{
    return 0;
}