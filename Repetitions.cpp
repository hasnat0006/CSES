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
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1000000007;
float pi = 3.141592653589793238462643383279502884197;
int inf = 1e18;

void solve()
{
    string s;
    cin >> s;
    int c = 1, ans = -1;
    for (int i = 1; s[i]; i++)
    {
        if (s[i] == s[i - 1])
            c++;
        else
        {
            ans = max(ans, c);
            c = 1;
        }
        // cout << "c-> " << c << "ans-> " << ans << endl;
    }
    ans = max(ans, c);
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}