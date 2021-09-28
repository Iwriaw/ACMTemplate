//初步验证正确
#include <bits/stdc++.h>
using namespace std;
struct PSegtree
{
    struct node
    {
        int val, son[2];
    };
    vector<node> t;
    vector<int> root;
    void init(int n)
    {
        t.clear();
        root.clear();
        root.push_back(build(1, n));
    }
    //init得到一颗完整的空线段树，区间[l, r]，根为root[0]
    int build(int l, int r)
    {
        t.push_back(node());
        int rt = t.size() - 1;
        if (l == r)
            return rt;
        int m = l + r >> 1;
        t[rt].son[0] = build(l, m);
        t[rt].son[1] = build(m + 1, r);
        return rt;
    }
    //用法：root.push_back(update(...))
    //若结点更新关系为一颗树，可以把root数组换为root树来查询祖先到后代链上第K大
    int update(int l, int r, int prt, const int& P, const int& V)//在prt线段树基础上位置P加V（因为是权值线段树，本质上是加入V个值P）
    {

        t.push_back(node());
        int rt = t.size() - 1;    
        t[rt].val = t[prt].val + V;
        t[rt].son[0] = t[prt].son[0];
        t[rt].son[1] = t[prt].son[1];
        if (l == r)
            return rt;
        int m = l + r >> 1;
        if (P <= m)
            t[rt].son[0] = update(l, m, t[prt].son[0], P, V);
        if (m < P)
            t[rt].son[1] = update(m + 1, r, t[prt].son[1], P, V);
        return rt;
    }
    int query(int l, int r, int lrt, int rrt, int k)//rrt - lrt线段树查询第k大
    {
        if (l == r)
            return l;
        int lval = t[t[rrt].son[0]].val - t[t[lrt].son[0]].val;
        int m = l + r >> 1;
        int ans = 0;
        if (k <= lval)
            ans = query(l, m, t[lrt].son[0], t[rrt].son[0], k);
        if (k > lval)
            ans = query(m + 1, r, t[lrt].son[1], t[rrt].son[1], k - lval);
        return ans;
    }
} pst;
const int N = 1e5;
int s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    pst.init(10);
    cout << pst.t.size() << endl;
    for (int i = 1; i <= n; i++)
        pst.root.push_back(pst.update(1, 10, pst.root[i - 1], s[i], 1));
    int m;
    cin >> m;
    while (m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        cout << pst.query(1, 10, pst.root[l - 1], pst.root[r], k) << endl;
    }
    return 0;
}