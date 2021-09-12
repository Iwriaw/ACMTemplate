#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;

struct binarylca
{
    vector<vector<int>> g;
    vector<vector<int>> par;
    vector<int> dep;
    binarylca(vector<vector<int>>& g, int root)
    {
        this->g = g;
        par = vector<vector<int>>(g.size(), vector<int>(20 + 1));
        dep = vector<int>(g.size());
        dfs(root, 0);
    }
    void dfs(int now, int pre)
    {
        par[now][0] = pre;
        dep[now] = dep[pre] + 1;
        for (int i = 1; i <= 20; i++)
        {
            par[now][i] = par[par[now][i - 1]][i - 1];
        }
        for (auto i : g[now])
            if (i != pre)
            {
                dfs(i, now);
            }
    }
    int lca(int x, int y)
    {
        if (dep[x] > dep[y])
            swap(x, y);
        int gap = dep[y] - dep[x];
        for (int i = 20; i >= 0; i--)
            if (gap >= (1 << i))
            {
                gap -= 1 << i;
                y = par[y][i];
            }
        if (x == y)
            return x;
        for (int i = 20; i >= 0; i--)
            if (par[x][i] != par[y][i])
            {
                x = par[x][i];
                y = par[y][i];
            }
        return par[x][0];
    }
};
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    g = vector<vector<int>>(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    binarylca lca = binarylca(g, 1);
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }
    return 0;
}