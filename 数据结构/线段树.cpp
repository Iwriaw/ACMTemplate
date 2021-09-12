#include <bits/stdc++.h>
using namespace std;
struct Segtree
{
    const static int N = 1e5;
    int seg[4 * N + 5], tag[4 * N + 5];
    void pushup(const int &rt)
    {
        seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
    }
    void pushdown(const int &rt, int ln, int rn)
    {
        if (tag[rt])
        {
            seg[rt << 1] += tag[rt] * ln;
            seg[rt << 1 | 1] += tag[rt] * rn;
            tag[rt << 1] += tag[rt];
            tag[rt << 1 | 1] += tag[rt];
            tag[rt] = 0;
        }
    }
    void clear(int l, int r, int rt)
    {
        if (l == r)
        {
            seg[rt] = 0;
            tag[rt] = 0;
            return;
        }
        int m = l + r >> 1;
        pushdown(rt, m - l + 1, r - m);
        if (seg[rt << 1])
            clear(l, m, rt << 1);
        if (seg[rt << 1 | 1])
            clear(m + 1, r, rt << 1 | 1);
        pushup(rt);
    }
    void add(int l, int r, int rt, const int &L, const int &R, const int &V)
    {
        if (L <= l && r <= R)
        {
            seg[rt] += V * (r - l + 1);
            tag[rt] += V;
            return;
        }
        int m = l + r >> 1;
        pushdown(rt, m - l + 1, r - m);
        if (L <= m)
            add(l, m, rt << 1, L, R, V);
        if (m < R)
            add(m + 1, r, rt << 1 | 1, L, R, V);
        pushup(rt);
    }
    int query(int l, int r, int rt, const int &L, const int &R)
    {
        if (L <= l && r <= R)
            return seg[rt];
        int ans = 0;
        int m = l + r >> 1;
        pushdown(rt, m - l + 1, r - m);
        if (L <= m)
            ans += query(l, m, rt << 1, L, R);
        if (m < R)
            ans += query(m + 1, r, rt << 1 | 1, L, R);
        return ans;
    }
};
int main()
{
    return 0;
}