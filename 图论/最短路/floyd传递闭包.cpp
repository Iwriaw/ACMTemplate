#include <bits/stdc++.h>
using namespace std;
struct floyd
{
    const static int N = 1e4 + 5;
    vector<bitset<N>> mat;
    void closure(vector<vector<int>> &g)
    {
        mat = vector<bitset<N>>(g.size());
        for (int i = 1; i < g.size(); i++)
            for (int j : g[i])
                mat[i].set(j);
        for (int k = 1; k < g.size(); k++)
            for (int i = 1; i < g.size(); i++)
                if (mat[i][k])
                    mat[i] = mat[i] | mat[k];
    }
};
int main()
{
    return 0;
}
