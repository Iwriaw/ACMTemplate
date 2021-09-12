//正确
#include <bits/stdc++.h>
using namespace std;
struct SA
{
    static const int N = 1e6;
    int sa[N + 5], rk[N + 5], ht[N + 5];
    int oldrk[2 * N + 5], id[N + 5], px[N + 5], cnt[N + 5];
    bool cmp(int x, int y, int w)
    {
        return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
    }
    void getSA(char str[])
    {
        int n = strlen(str + 1);
        int p, m = 300;
        for (int i = 1; i <= n; i++)
            cnt[rk[i] = str[i]]++;
        for (int i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--)
            sa[cnt[rk[i]]--] = i;
        for (int w = 1; w < n; w <<= 1, m = p)
        {
            p = 0;
            for (int i = n; i > n - w; i--)
                id[++p] = i;
            for (int i = 1; i <= n; i++)
                if (sa[i] > w)
                    id[++p] = sa[i] - w;
            for (int i = 1; i <= m; i++)
                cnt[i] = 0;
            for (int i = 1; i <= n; i++)
                cnt[px[i] = rk[id[i]]]++;
            for (int i = 1; i <= m; i++)
                cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; i--)
                sa[cnt[px[i]]--] = id[i];
            for (int i = 1; i <= n; i++)
                oldrk[i] = rk[i];
            p = 0;
            for (int i = 1; i <= n; i++)
                rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
            if (p == n)
            {
                for (int i = 1; i <= n; i++)
                    sa[rk[i]] = i;
                break;
            }
        }
        for (int i = 1, j = 0; i <= n; i++)
        {
            if (j > 0)
                j -= 1;
            while (str[i + j] == str[sa[rk[i] - 1] + j])
                j += 1;
            ht[rk[i]] = j;
        }
    }
};
int main()
{
    return 0;
}