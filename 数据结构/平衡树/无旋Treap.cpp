#include <bits/stdc++.h>
using namespace std;
struct Treap
{
    struct node
    {
        int pri, val, siz;
        node* son[2];
    };
    void pushup(node* now)
    {
        now->siz = 1;
        if (now->son[0])
            now->siz += now->son[0]->siz;
        if (now->son[1])
            now->siz += now->son[1]->siz;
    }
    pair<node*, node*> split(node* now, int val)
    {
        if (now == NULL)
            return {NULL, NULL};
        if (now->val > val)//右子树>val不用分
        {
            auto nxt = split(now->son[0], val);
            now->son[0] = nxt.second;
            return {nxt.first, now};
        }
        else//now->val <= val，左子树<=val不用分
        {
            auto nxt = split(now->son[1], val);
            now->son[1] = nxt.first;
            return {now, nxt.second};
        }
        pushup(now);
    }
    node* merge(node* u, node* v)//两个Treap dfs序拼接
    {
        if (u == NULL)
            return v;
        if (v == NULL)
            return u;
        if (u->pri > v->pri)//优先级大的当爸爸
        {
            u->son[1] = merge(u->son[1], v);
            pushup(u);
            return u;
        }
        else
        {
            v->son[0] = merge(u, v->son[0]);
            pushup(v);
            return v;
        }
    }
    //接下来的插入删除操作均基于上述分裂合并两个操作，并且各个函数相互独立
    //待续
};
int main()
{

    return 0;
}