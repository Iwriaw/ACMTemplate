//正确
#include <bits/stdc++.h>
using namespace std;
struct FFT
{
    static const int N = 1 << 20;
    const double PI = acos(-1);
    int rev[N + 5];
    void change(complex<double> s[], int len)
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
    void dft(complex<double> s[], int len, int on)
    {
        change(s, len);
        for (int i = 2; i <= len; i <<= 1)
        {
            complex<double> wn = {cos(2 * PI / i), sin(on * 2 * PI / i)};
            for (int j = 0; j < len; j += i)
            {
                complex<double> w = {1, 0};
                for (int k = j; k < j + i / 2; k++)
                {
                    complex<double> u = s[k];
                    complex<double> t = w * s[k + i / 2];
                    s[k] = u + t;
                    s[k + i / 2] = u - t;
                    w *= wn;
                }
            }
        }
        if (on == -1)
            for (int i = 0; i < len; i++)
                s[i] /= len;
    }
};
int main()
{
    return 0;
}