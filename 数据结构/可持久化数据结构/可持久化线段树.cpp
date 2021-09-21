#include <bits/stdc++.h>
using namespace std;
struct Segtree
{
    struct node
    {
        int val, son[2];
    };
    vector<node> t;
    vector<int> root;
    void init(int n)
    {
        t = vector<node>(1);
        root.clear();
        root.push_back(build(1, n));
    }
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
    int update(int l, int r, int rt, int v)
    {

    }
};
int main()
{
    return 0;
}