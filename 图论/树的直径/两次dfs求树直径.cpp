#include <bits/stdc++.h>
using namespace std;
//不适用于带负权边的树
struct TreeD
{
    static const int N = 1e5;
    int u, v, d;//uv为直径的两个端点，d为直径长度
    int dis[N + 5];
    void getdiameter(vector<int> g[], int n)
    {
        dis[1] = 0;
        u = dfs(1, 0, g, n);
        dis[u] = 0;
        v = dfs(u, 0, g, n);
        d = dis[v];
    }
    int dfs(int now, int pre, vector<int> g[], int n)
    {
        int ans = now;
        dis[now] = dis[pre] + 1;
        for (int i : g[now])
            if (i != pre)
            {
                int tmp = dfs(i, now, g, n);
                if (dis[tmp] > dis[ans])
                    ans = tmp;
            }
        return ans;
    }
};
int main()
{
    return 0;
}