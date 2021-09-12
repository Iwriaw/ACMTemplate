#include <bits/stdc++.h>
using namespace std;
struct SAM
{
    struct node
    {
        int len, link;
        map<char, int> nxt;
    };
    vector<node> g;
    int lst;
    void init()
    {
        g = vector<node>(1);
        g[0].link = -1;
        lst = 0;
    }
    void extend(char c)
    {
        g.push_back(node());
        int now = g.size() - 1;
        g[now].len = g[lst].len + 1;
        int p = lst;
        while (p != -1 && g[p].nxt.find(c) == g[p].nxt.end())
        {
            g[p].nxt[c] = now;
            p = g[p].link;
        }
        if (p == -1)
        {
            g[now].link = 0;
        }
        else
        {
            int q = g[p].nxt[c];
            if (g[p].len + 1 == g[q].len)
            {
                g[now].link = q;
            }
            else
            {
                g.push_back(node());
                int clone = g.size() - 1;
                g[clone].len = g[p].len + 1;
                g[clone].nxt = g[q].nxt;
                g[clone].link = g[q].link;
                while (p != -1 && g[p].nxt[c] == q)
                {
                    g[p].nxt[c] = clone;
                    p = g[p].link;
                }
                g[q].link = g[now].link = clone;
            }
        }
        lst = now;
    }
};
int main()
{
    return 0;
}