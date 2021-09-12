#include <bits/stdc++.h>
using namespace std;
struct ISAP
{
    static const int N = 1e3;//点数
    static const int INF = 0x3f3f3f3f;
    struct edge
    {
        int to, cap;
    };
    vector<edge> e;
    vector<int> g[N + 5];
    int n, src, snk;
    int dep[N + 5], pre[N + 5], num[N + 5], cur[N + 5];
    void addedge(int u, int v, int w)
    {
        e.push_back({v, w});
        g[u].push_back(e.size() - 1);
        e.push_back({u, 0});
        g[u].push_back(e.size() - 1);
    }
    void bfs()
    {
        for (int i = 1; i <= n; i++)
            dep[i] = n;
        dep[snk] = 0;
        queue<int> q;
        q.push(snk);
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i : g[now])
                if (dep[e[i].to] == n && e[i ^ 1].cap > 0)
                {
                    dep[e[i].to] = dep[now] + 1;
                    q.push(e[i].to);
                }
        }
    }
    int augment()
    {
        int flow = INF;
        for (int i = snk; i != src; i = e[pre[i] ^ 1].to)
            flow = min(flow, e[pre[i]].cap);
        for (int i = snk; i != src; i = e[pre[i] ^ 1].to)
        {
            e[pre[i]].cap -= flow;
            e[pre[i] ^ 1].cap += flow;
        }
        return flow;
    }
    int getmaxflow()
    {
        for (int i = 1; i <= n; i++)
        {
            pre[i] = 0;
            num[i] = 0;
            cur[i] = 0;
        }
        bfs();
        for (int i = 1; i <= n; i++)
            num[dep[i]]++;
        int ans = 0;
        int now = src;
        while (dep[src] < n)
        {
            if (now == snk)
            {
                ans += augment();
                now = src;
            }
            bool nxt = 0;
            for (int& i = cur[now]; i < g[now].size(); i++)
            {
                int j = g[now][i];
                if (e[j].cap > 0 && dep[e[j].to] == dep[now] - 1)
                {
                    now = e[j].to;
                    pre[now] = j;
                    nxt = 1;
                    break;
                }
            }
            if (nxt == 0)
            {
                int mindep = n - 1;
                for (int i : g[now])
                    if (e[i].cap)
                        mindep = min(mindep, dep[e[i].to]);
                num[dep[now]]--;
                if (num[dep[now]] == 0)
                    break;
                dep[now] = mindep + 1;
                num[dep[now]]++;
                cur[now] = 0;
                if (now != src)
                    now = e[pre[now] ^ 1].to;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}