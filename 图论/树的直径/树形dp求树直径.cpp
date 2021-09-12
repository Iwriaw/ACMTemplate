#include <bits/stdc++.h>
using namespace std;
struct TreeD
{
    static const int N = 1e5;
    int u, v, d;//uv为直径的两个端点，d为直径长度
    int son[N + 5][2], dis[N + 5][2];
    void getdiameter(vector<int> g[], int n)
    {
        dfs(1, 0, g, n);
    }
    void dfs(int now, int pre, vector<int> g[], int n)
    {
        for (int i : g[now])
            if (i != pre)
            {
                dfs(i, now, g, n);
                int tmp = dis[i][0] + 1;
                if (tmp > dis[now][0])
                {
                    son[now][1] = son[now][0];
                    dis[now][1] = dis[now][0];
                    son[now][0] = i;
                    dis[now][0] = tmp;
                }
                else if (tmp > dis[now][1])
                {
                    son[now][1] = i;
                    dis[now][1] = tmp;
                }
            }
        if (dis[now][0] + dis[now][1] > d)
        {
            u = son[now][0];
            v = son[now][1];
            d = dis[now][0] + dis[now][1];
        }
    }
};
int main()
{
    return 0;
}