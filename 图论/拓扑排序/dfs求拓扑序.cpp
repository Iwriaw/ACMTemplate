#include <bits/stdc++.h>
using namespace std;
struct TopoSort
{
    vector<int> vis, topo;
    bool dfs(int now, vector<int> g[])
    {
        bool ok = 1;
        vis[now] = -1;
        for (int i : g[now])
        {
            if (vis[i] < 0)
                return 0;
            else if (vis[i] == 0)
                ok &= dfs(i, g);
        }
        vis[now] = 1;
        topo.push_back(now);
        return ok;
    }
    bool sort(vector<int> g[], int n)
    {
        topo = vector<int>();
        vis = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
            if (vis[i] == 0 && dfs(i, g) == 0)
                return 0;
        reverse(topo.begin(), topo.end());
        return 1;
    }
};
int main()
{

    return 0;
}