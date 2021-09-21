#include <bits/stdc++.h>
using namespace std;
struct TarjanSCC
{
    static const int N = 1e5;
    int scc[N + 5], siz[N + 5], sccc;//结点所属强连通分量编号，强连通分量i的大小，强连通分量总数
    int dfn[N + 5], low[N + 5], dfsc;
    stack<int> stk;
    int instk[N + 5];
    void get(vector<int> g[], int n)
    {
        dfsc = sccc = 0;
        for (int i = 1; i <= n; i++)
            dfn[i] = siz[i] = 0;
        for (int i = 1; i <= n; i++)
            if (dfn[i] == 0)
                dfs(i, g);
    }
    void dfs(int now, vector<int> g[])
    {
        low[now] = dfn[now] = ++dfsc;
        stk.push(now);
        instk[now] = 1;
        for (auto i : g[now])
            if (dfn[i] == 0)
            {
                dfs(i, g);
                low[now] = min(low[now], low[i]);
            }
            else if (instk[i])
            {
                low[now] = min(low[now], dfn[i]);
            }
        if (dfn[now] == low[now])
        {
            sccc += 1;
            while (stk.top() != now)
            {
                scc[stk.top()] == sccc;
                siz[sccc] += 1;
                instk[stk.top()] = 0;
                stk.pop();
            }
            scc[stk.top()] = sccc;
            siz[sccc] += 1;
            instk[stk.top()] = 0;
            stk.pop();
        }
    }
};
int main()
{
    return 0;
}