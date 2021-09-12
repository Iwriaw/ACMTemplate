//求异或和大于等于k且权值最大的值
//正确
#include <bits/stdc++.h>
using namespace std;
struct Trie
{
    struct node
    {
        int son[2];
        int val;
    };
    vector<node> t;
    void init()
    {
        t = vector<node>(1);
    }
    void add(int num, int val)
    {
        int now = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (num >> i) & 1;
            if (t[now].son[b] == 0)
            {
                t.push_back(node());
                t[now].son[b] = t.size() - 1;
            }
            now = t[now].son[b];
            t[now].val = max(t[now].val, val);
        }
    }
    int query(int num, int k)
    {
        int ans = 0;
        int now = 0;
        for (int i = 30; i >= 0; i--)
        {
            int b = (num >> i) & 1;
            int kb = (k >> i) & 1;
            if (kb == 0)//异或和前缀相同，如果k该位为0，那么异或后该位为1的数一定比k大。
                ans = max(ans, t[t[now].son[!b]].val);
            if (t[now].son[b ^ kb] == 0)
                return ans;
            now = t[now].son[b ^ kb];//保持异或和前缀与k相同
        }
        ans = max(ans, t[now].val);//异或和等于k的情况
        return ans;
    }
};
int main()
{
    return 0;
}