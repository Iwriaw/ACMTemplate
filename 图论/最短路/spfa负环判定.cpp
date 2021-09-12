#include <bits/stdc++.h>
using namespace std;
struct spfa
{
    const static int INF = 0x3f3f3f3f;
    vector<int> vis, dis;
    bool shortestpath(vector<vector<pair<int, int>>>& g, int st)
    {
        vis = vector<int>(g.size());
        dis = vector<int>(g.size(), INF);
        queue<int> q;
        q.push(st);
        vis[st] = 1;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            if (vis[now] > g.size())
                return 0;
            vis[now] = -vis[now];
            for (auto i : g[now])
                if (dis[i.first] > dis[now] + i.second)
                {
                    dis[i.first] = dis[now] + i.second;
                    if (vis[i.first] <= 0)
                    {
                        vis[i.first] = -vis[i.first] + 1;
                        q.push(i.first);
                    }
                }
        }
    }
};
int main()
{
    return 0;
}