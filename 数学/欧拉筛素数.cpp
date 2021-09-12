//正确
#include <bits/stdc++.h>
using namespace std;
struct Euler
{
    const static int N = 1e7;
    bool isprime[N + 5];
    vector<int> prime;
    void sieve()
    {
        prime.clear();
        for (int i = 1; i <= N; i++)
            isprime[i] = 1;
        for (int i = 2; i <= N; i++)
        {
            if (isprime[i])
                prime.push_back(i);
            for (int j = 0; j < prime.size() && i * prime[j] <= N; j++)
            {
                isprime[i * prime[j]] = 0;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }
};
int main()
{
    return 0;
}