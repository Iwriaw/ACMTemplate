#include <bits/stdc++.h>
using namespace std;
struct TreeC
{
    static const int N = 1e5;
    int siz[N + 5], wei[N + 5];
    int c; //重心结点编号
    void getc(vector<int> g[], int n)
    {
        dfs(1, 0, g, n);
        c = min_element(wei + 1, wei + 1 + n) - wei;
    }
    void dfs(int now, int pre, vector<int> g[], int n)
    {
        siz[now] = 1;
        wei[now] = 0;
        for (auto i : g[now])
            if (i != pre)
            {
                dfs(i, now, g, n);
                siz[now] += siz[i];
                wei[now] = max(wei[now], siz[i]);
            }
        wei[now] = max(wei[now], n - siz[now]);
    }
};
int main()
{
    return 0;
}