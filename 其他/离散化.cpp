#include <bits/stdc++.h>
using namespace std;
struct Disc
{
    vector<int> srt, ans;
    vector<int> get(vector<int> &s)
    {
        srt = s;
        ans = vector<int>(s.size());
        sort(srt.begin() + 1, srt.end());
        srt.resize(unique(srt.begin() + 1, srt.end()) - srt.begin());
        for (int i = 1; i < s.size(); i++)
            ans[i] = lower_bound(srt.begin() + 1, srt.end(), s[i]) - srt.begin();
        return ans;
    }
};
int main()
{
    return 0;
}