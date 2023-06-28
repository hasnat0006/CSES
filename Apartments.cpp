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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> person(n), app(m), mark(m);
    for (int i = 0; i < n; i++)
        cin >> person[i];
    for (int i = 0; i < m; i++)
        cin >> app[i];
    sort(vf(person));
    sort(vf(app));
    int ans = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(app.begin() + x, app.end(), (person[i] - k));
        int val = it - app.begin();
        // debug(val);
        if (abs(app[val] - person[i]) <= k)
            ans++, x = val + 1;
    }
    // debug(mark);
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