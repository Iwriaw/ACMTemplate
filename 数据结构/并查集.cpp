//正确
struct DSU
{
    static const int N = 1e5;
    int par[N + 5];
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
            par[i] = i;
    }
    int getpar(int x)
    {
        return x == par[x] ? x : par[x] = getpar(par[x]);
    }
    bool merge(int x, int y)
    {
        int px = getpar(x);
        int py = getpar(y);
        if (px == py)
            return 0;
        par[px] = py;
        return 1;
    }
};