//正确
#include <bits/stdc++.h>
using namespace std;
struct Block
{
    static const int N = 1e5 + 1;
    int n, num, len;
    int st[N + 5], ed[N + 5], siz[N + 5], belong[N + 5];
    int seg[N + 5], val[N + 5];
    void init(int n)
    {
        this->n = n;
        len = sqrt(n);
        num = n / len;
        for (int i = 1; i <= num; i++)
        {
            st[i] = len * (i - 1) + 1;
            ed[i] = len * i;
        }
        if (num * len < n)
        {
            num += 1;
            st[num] = (num - 1) * len + 1;
            ed[num] = n;
        }
        for (int i = 1; i <= num; i++)
        {
            for (int j = st[i]; j <= ed[i]; j++)
                belong[j] = i;
            siz[i] = ed[i] - st[i] + 1;
        }
        for (int i = 1; i <= num; i++)
            seg[i] = 0;
        for (int i = 1; i <= n; i++)
            val[i] = 0;
    }
    void add(int p, int v)
    {
        if (val[p] == 0 && v > 0)
            seg[belong[p]] += 1;
        if (val[p] > 0 && val[p] + v == 0)
            seg[belong[p]] -= 1;
        val[p] += v;
    }
    int query(int l, int r)
    {
        int ans = 0;
        int bl = belong[l];
        int br = belong[r];
        for (int i = bl + 1; i <= br - 1; i++)
            ans += seg[i];
        if (bl == br)
        {
            for (int i = l; i <= r; i++)
                ans += (val[i] != 0);
        }
        else
        {
            for (int i = l; i <= ed[bl]; i++)
                ans += (val[i] != 0);
            for (int i = st[br]; i <= r; i++)
                ans += (val[i] != 0);
        }
        return ans;
    }
};
int main()
{
    return 0;
}