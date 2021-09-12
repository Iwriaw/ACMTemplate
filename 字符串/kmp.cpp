#include <bits/stdc++.h>
using namespace std;
struct KMP
{
    static const int N = 1e5;
    int pi[N + 5];
    void getpi(char str[])
    {
        int len = strlen(str + 1);
        pi[1] = 0;
        for (int i = 2; i <= len; i++)
        {
            int j = pi[i - 1];
            while (j && str[i] != str[j + 1])
                j = pi[j];
            if (str[i] == str[j + 1])
                j += 1;
            pi[i] = j;
        }
    }
};
int main()
{
    return 0;
}