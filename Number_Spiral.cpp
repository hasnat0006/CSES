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
    int x, ans, y;
    cin >> x >> y;
    int mx = max(x, y);
    if (mx % 2 == 0)
    {
        if (y == 1)
            ans = mx * mx;
        else if (x == mx)
            ans = (mx * mx) - y + 1;
        else
        {
            int temp = (mx * mx) - mx + 1;
            ans = temp - (mx - x);
        }
    }
    else
    {
        if (x == 1)
            ans = mx * mx;
        else if (y == mx)
            ans = (mx * mx) - x + 1;
        else
        {
            int temp = (mx * mx) - mx + 1;
            ans = temp - (mx - y);
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}