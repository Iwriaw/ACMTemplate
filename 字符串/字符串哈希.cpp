//一个模数很容易挂，建议两个模数一起判
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct StringHash
{
    static const int N = 1e6;//N: 字符串长度
    int B = 133, M = 1e9 + 7;//B: 进制数, M: 模数
    int p[N + 5], h[N + 5];//p: b的阶乘, h: 前缀哈希
    void init(char str[])
    {
        int len = strlen(str + 1);
        p[0] = 1, h[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            p[i] = p[i - 1] * B % M;
            h[i] = (h[i - 1] * B + (str[i] - 'a' + 1)) % M;
        }
    }
    int gethash(int l, int r)
    {
        return (h[r] - h[l - 1] * p[r - l + 1] % M + M) % M;
    }
};
int main()
{
    return 0;
}