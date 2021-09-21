#include <bits/stdc++.h>
using namespace std;
struct Bitree
{
    vector<int> t;
    void init(int n)
    {
        t = vector<int>(n + 1);
    }
    void add(int p, int v)
    {
        for (int i = p; i < t.size(); i += i & -i)
            t[i] += v;
    }
    int sum(int p)
    {
        int ans = 0;
        for (int i = p ; i >= 1; i -= i & -i)
            ans += t[i];
        return ans;
    }
    int query(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};
int main()
{
    return 0;
}