#include <bits/stdc++.h>
using namespace std;
//求字典序最小拓扑序
struct Toposort
{
    vector<int> indeg, topo;
    bool sort(vector<int> g[], int n)
    {
        topo = vector<int>();
        indeg = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)
            for (int j : g[i])
                indeg[j] += 1;
        set<int> st;
        for (int i = 1; i <= n; i++)
            if (indeg[i] == 0)
                st.insert(i);
        while (!st.empty())
        {
            int now = *st.begin();
            st.erase(st.begin());
            topo.push_back(now);
            for (int i : g[now])
                if (--indeg[i] == 0)
                    st.insert(i);
        }
        return topo.size() == n;
    }
};
int main()
{
    return 0;
}