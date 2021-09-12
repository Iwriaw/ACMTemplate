#include <bits/stdc++.h>
using namespace std;
struct floyd
{
    static const int INF = 0x3f3f3f3f;
    vector<vector<int>> dis;
    void shortestpath(vector<vector<pair<int, int>>> &g)
    {
        dis = vector<vector<int>>(g.size(), vector<int>(g.size(), INF));
        for (int i = 1; i < g.size(); i++)
            dis[i][i] = 0;
        for (int i = 1; i < g.size(); i++)
            for (auto j : g[i])
                dis[i][j.first] = min(dis[i][j.first], j.second);
        for (int k = 1; k < g.size(); k++)
            for (int i = 1; i < g.size(); i++)
                for (int j = 1; j < g.size(); j++)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
};
int main()
{
    return 0;
}