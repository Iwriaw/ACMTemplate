#include <bits/stdc++.h>
using namespace std;
struct Bitree
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
        for (int i = p ; i >= 1; i -= i & -i)
            ans += ta[i];
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