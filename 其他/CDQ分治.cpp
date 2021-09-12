#include <bits/stdc++.h>
using namespace std;
struct bitree
{
    vector<int> ta;
    void init(int n)
    {
        ta = vector<int>(n + 1);
    }
    void add(int p, int v)
    {
        for (int i = p; i < ta.size(); i += i & -i)
            ta[i] += v;
    }
    int sum(int p)
    {
        int ans = 0;
        for (int i = p; i >= 1; i -= i & -i)
            ans += ta[i];
        return ans;
    }
    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};
struct CDQ
{
    bitree bt;
    vector<int> rnk;
    struct comp
    {
        int cid;
        bool operator()(vector<int> a, vector<int> b)
        {
            return a[cid] < b[cid];
        }
    } cmp;
    void solve(vector<vector<int>> &tri)
    {
        bt.init(tri.size());
        rnk = vector<int>(tri.size());
        cmp.cid = 1;
        sort(tri.begin() + 1, tri.end(), cmp);
        cmp.cid = 2;
        dac(tri, 1, tri.size() - 1);
    }
    void dac(vector<vector<int>> &tri, int l, int r)
    {
        if (l == r)
            return;
        int m = l + r >> 1;
        dac(tri, l, m);
        dac(tri, m + 1, r);
        for (int i = m + 1, j = l; i <= r; i++)
        {
            while (j <= m && tri[i][2] >= tri[j][2])
            {
                bt.add(tri[j][3], 1);
                j++;
            }
            rnk[tri[i][0]] += bt.query(1, tri[i][3]);
        }
        for (int i = m + 1, j = l; i <= r; i++)
            while (j <= m && tri[i][2] >= tri[j][2])
            {
                bt.add(tri[j][3], -1);
                j++;
            }
        sort(tri.begin() + l, tri.begin() + r + 1, cmp);
    }
};
int main()
{
    return 0;
}