#include <bits/stdc++.h>
using namespace std;
struct TopoSort
{
    vector<int> vis, topo;
    bool dfs(int now, vector<vector<int>> &g)
    {
        vis[now] = -1;
        for (int i : g[now])
        {
            if (vis[i] < 0)
                return 0;
            else if (vis[i] == 0)
                dfs(i, g);
        }
        vis[now] = 1;
        topo.push_back(now);
        return 1;
    }
    bool sort(vector<vector<int>> &g)
    {
        topo = vector<int>();
        vis = vector<int>(g.size());
        for (int i = 0; i < g.size(); i++)
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