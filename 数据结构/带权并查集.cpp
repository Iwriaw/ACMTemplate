struct DSU
{
    static const int N = 1e5;
    int par[N + 5], val[N + 5];
    void init(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int getpar(int x)
    {
        if (x == par[x])
            return x;
        int px = par[x];
        par[x] = getpar(px);
        val[x] += val[px];
        return par[x];
    }
    bool merge(int x, int y, int w)
    {
        int px = getpar(x);
        int py = getpar(y);
        if (px == py)
            return 0;
        par[px] = py;
        val[px] = -val[x] + val[y] + w;
    }
};