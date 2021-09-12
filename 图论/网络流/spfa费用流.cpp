#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
struct edge
{
    int to, cap, cost, what;
} e[200005];
vector<int> g[N];
int EN, NN, S, T, pre[N], dis[N], vis[N];
//EN边数 NN点数 S源点 T汇点
void init()
{
    for (int i = 1; i <= NN; i++)
        pre[i] = 0;
}
bool spfa()
{
    for (int i = 1; i <= NN; i++)
    {
        dis[i] = 0x3f3f3f3f;
        vis[i] = 0;
        pre[i] = 0;
    }
    dis[S] = 0;
    deque<int> q;
    q.push_back(S);
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        vis[now] = 0;
        for (int i : g[now])
            if (e[i].cap > 0 && dis[now] + e[i].cost < dis[e[i].to])
            {
                dis[e[i].to] = dis[now] + e[i].cost;
                pre[e[i].to] = i;
                if (vis[e[i].to] == 0)
                {
                    vis[e[i].to] = 1;
                    if (q.empty() || dis[e[i].to] < dis[q.front()])//SLF
                        q.push_front(e[i].to);
                    else
                        q.push_back(e[i].to);
                 }
            }
    }
    return dis[T] != 0x3f3f3f3f;
}
pair<int, int> augment()
{
    int mf = 0x3f3f3f3f, cost = 0;
    for (int u = T; u != S; u = e[pre[u] ^ 1].to)
    {
        mf = min(mf, e[pre[u]].cap);
        cost += e[pre[u]].cost;
    }
    for (int u = T; u != S; u = e[pre[u] ^ 1].to)
        e[pre[u]].cap -= mf, e[pre[u] ^ 1].cap += mf;
    return pair<int, int>(mf, mf * cost);
}
pair<int, int> maxflow()
{
    pair<int, int> ans;
    while (spfa())
    {
        pair<int, int> aug = augment();
        ans.first += aug.first;
        ans.second += aug.second;
    }
    return ans;
}
void addedge(int u, int v, int w, int c)
{
    g[u].push_back(EN);
    e[EN++] = edge{v, w, c};
    g[v].push_back(EN);
    e[EN++] = edge{u, 0, -c};
}
int s[105];
int main()
{
    int n;
    cin >> n;
    NN = n + 2;
    S = n + 1;
    T = n + 2;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[0] += s[i];
    }
    s[0] /= n;
    for (int i = 1; i <= n; i++)
    {
        addedge(S, i, s[i], 0);
        addedge(i, T, s[0], 0);
        int prei = (i + n - 2) % n + 1;
        int nxti = i % n + 1;
        addedge(i, prei, 0x3f3f3f3f, 1);
        addedge(i, nxti, 0x3f3f3f3f, 1);
    }
    cout << maxflow().second << endl;
    return 0;
}