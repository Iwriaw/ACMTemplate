#include <bits/stdc++.h>
using namespace std;

struct TreeChainSpliter {
    struct node {
        int par;  // parent node
        int dep;  // deep
        int siz;  // size
        int hvy;  // heavy child
        int top;  // top node of chain
        int dfo;  // dfs order
    };

    int dfs_stamp;  // dfs stamp
    vector<int> *g;  // origin tree
    vector<node> nodes;  // splited tree

    void init(int n, vector<int> g[]) {
        this->g = g;
        nodes = vector<node>(n + 1);
    }

    void split(int root) {
        dfs_stamp = 0;
        dfs1(root, 0);
        dfs2(root, 0, root);
    }

    // calculate hvy, siz, par, dep
    void dfs1(int now, int pre) {
        nodes[now].hvy = 0;
        nodes[now].siz = 1;
        nodes[now].par = pre;
        nodes[now].dep = nodes[pre].dep + 1;
        for (int nxt : g[now]) {
            if (nxt != pre) {
                dfs1(nxt, now);
                nodes[now].siz += nodes[nxt].siz;
                if (nodes[nxt].siz > nodes[nodes[now].hvy].siz) {
                    nodes[now].hvy = nxt;
                }
            }
        }
    }

    // calculate top, dfo
    void dfs2(int now, int pre, int top) {
        nodes[now].top = top;
        nodes[now].dfo = ++dfs_stamp;
        if (nodes[now].hvy) {
            dfs2(nodes[now].hvy, now, top);
        }
        for (int nxt : g[now]) {
            if (nxt != pre && nxt != nodes[now].hvy) {
                dfs2(nxt, now, nxt);
            }
        }
    }

    // query path bewteen two node
    int query(int x, int y) {
        int ans = 0;  // answer

        int top_x = nodes[x].top;
        int top_y = nodes[y].top;
        while (top_x != top_y) {
            if (nodes[top_x].dep >= nodes[top_y].dep) {
                ans += _query(nodes[top_x].dfo, nodes[x].dfo);
                x = nodes[top_x].par;
                top_x = nodes[x].top;
            } else {
                ans += _query(nodes[top_y].dfo, nodes[y].dfo);
                y = nodes[top_y].par;
                top_y = nodes[y].top;
            }
        }
        if (nodes[x].dep >= nodes[y].dep) {
            ans += _query(nodes[x].dfo, nodes[y].dfo);
        } else {
            ans += _query(nodes[y].dfo, nodes[x].dfo);
        }
        return ans;
    }

    int _query(int l, int r) {
        // customize your query here or directly modify the _query above
        return 0;
    }
};

int main() {
    return 0;
}