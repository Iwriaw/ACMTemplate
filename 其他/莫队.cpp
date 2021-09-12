//正确
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int s[N + 5];
struct Mo
{
    static const int N = 1e5;
    struct query
    {
        int id, l, r, d, u;
    } q[N + 5];
    struct comp
    {
        int siz;
        bool operator()(query a, query b)
        {
            int ba = (a.l + siz - 1) / siz;
            int bb = (b.l + siz - 1) / siz;
            return ba < bb || (ba == bb && a.r < b.r);
        }
    } cmp;
    int ans[N + 5];
    void update(int p, int v)
    {
    }
    void solve(int n)
    {
        cmp.siz = sqrt(N);
        sort(q + 1, q + 1 + n, cmp);
        int l = 1, r = 0;
        for (int i = 1; i <= n; i++)
        {
            while (l > q[i].l)
                update(s[--l], 1);
            while (r < q[i].r)
                update(s[++r], 1);
            while (l < q[i].l)
                update(s[l++], -1);
            while (r > q[i].r)
                update(s[r--], -1);
        }
    }
};
int main()
{
    return 0;
}