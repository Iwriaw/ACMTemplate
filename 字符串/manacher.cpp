#include <bits/stdc++.h>
using namespace std;
struct Manacher
{
    static const int N = 1e5;
    int d[N + 5];//奇回文半径 #a#b#a#c#a#b#a
    void getd(char str[])
    {
        int len = strlen(str + 1);
        for (int i = 1, l = 0, r = 0; i <= len; i++)
        {
            int j = i > r ? 1 : min(d[l + r - i], r - i + 1);
            while (1 <= i - j && i - j <= len && str[i - j] == str[i + j])
                j++;
            d[i] = j;
            if (i + j - 1 > r)
            {
                l = i - j + 1;
                r = i + j - 1;
            }
        }
    }
};
int main()
{
    return 0;
}