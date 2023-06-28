//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

#define int long long
#define float long double
#define pb push_back
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

using namespace std;

vector<int> createLPS(string &pattern)
{
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < pattern.length();)
    {
        if (pattern[index] == pattern[i])
        {
            lps[i] = index + 1;
            index++, i++;
        }
        else
        {
            if (index != 0)
                index = lps[index - 1];
            else
                lps[i] = index, i++;
        }
    }
    return lps;
}

int kmp(string &text, string &pattern)
{
    int cnt_of_match = 0;
    vector<int> lps = createLPS(pattern);
    // debug(lps);
    int i = 0, j = 0; // i -> text, j -> pattern
    while (i < text.length())
    {
        if (text[i] == pattern[j])
            i++, j++;
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == pattern.length())
        {
            cnt_of_match++;
            // the index where match found -> (i - pattern.length());
            j = lps[j - 1];
        }
    }
    return cnt_of_match;
}

void solve()
{
    string text, pattern;
    cin >> text >> pattern;
    cout << kmp(text, pattern) << endl;
}

int32_t main()
{
    // YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
