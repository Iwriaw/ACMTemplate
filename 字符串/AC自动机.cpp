#include <bits/stdc++.h>
using namespace std;
struct ACA
{
    struct node
    {
        int son[26], fail, dep, hav;
    };
    vector<node> t;
    void init()
    {
        t = vector<node>(1);
    }
    void add(char str[])
    {
        int now = 0;
        int len = strlen(str + 1);
        for (int i = 1; i <= len; i++)
        {
            int c = str[i] - 'a';
            if (t[now].son[c] == 0)
            {
                t.push_back(node());
                t[now].son[c] = t.size() - 1;
                t[t.size() - 1].dep = t[now].dep + 1;
            }
            now = t[now].son[c];
        }
        t[now].hav = 1;
    }
    void getfail()
    {
        queue<int> q;
        for (int i = 0; i < 26; i++)
            if (t[0].son[i])
                q.push(t[0].son[i]);
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
                if (t[now].son[i])
                {
                    t[t[now].son[i]].fail = t[t[now].fail].son[i];
                    q.push(t[now].son[i]);
                }
                else
                {
                    t[now].son[i] = t[t[now].fail].son[i];
                }
        }
    }

};
int main()
{
    return 0;
}