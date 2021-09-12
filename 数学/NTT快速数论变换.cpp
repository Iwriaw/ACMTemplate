//正确
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct NTT
{
    static const int N = 1 << 20;
    static const int M = 998244353;
    int rev[N + 5];
    int qpow(int a, int b)
    {
        int ans = 1;
        while (b)
        {
            if (b & 1)
                ans = ans * a % M;
            a = a * a % M;
            b >>= 1;
        }
        return ans;
    }
    void change(int s[], int len)
    {
        for (int i = 0; i < len; i++)
        {
            rev[i] = rev[i >> 1] >> 1;
            if (i & 1)
                rev[i] |= len >> 1;
        }
        for (int i = 0; i < len; i++)
            if (i < rev[i])
                swap(s[i], s[rev[i]]);
    }
    void dft(int s[], int len, int on)
    {
        change(s, len);
        for (int i = 2; i <= len; i <<= 1)
        {
            int gn = qpow(3, (M - 1) / i);
            for (int j = 0; j < len; j += i)
            {
                int g = 1;
                for (int k = j; k < j + i / 2; k++)
                {
                    int u = s[k];
                    int t = g * s[k + i / 2] % M;
                    s[k] = u + t;
                    s[k + i / 2] = u - t;
                    g = g * gn % M;
                }
            }
        }
        if (on == -1)
        {
            reverse(s + 1, s + len);
            int inv = qpow(len, M - 2);
            for (int i = 0; i < len; i++)
                s[i] = s[i] * inv % M;
        }
    }
};
int main()
{
    return 0;
}