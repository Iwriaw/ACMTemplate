//z-function
#include <bits/stdc++.h>
using namespace std;
struct Zfunc
{
    static const int N = 1e5;
    int z[N + 5];
    void getz(char str[])
    {
        int len = strlen(str + 1);
        z[1] = len;
        for (int i = 2, l = 0, r = 0; i <= len; i++)
        {
            if (i <= r)
                z[i] = min(z[i - l + 1], r - i + 1);
            while (i + z[i] <= len && str[z[i] + 1] == str[i + z[i]])
                z[i] += 1;
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
    }
};
int main()
{
    return 0;
}