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

void solve() {
    int n;
    string v;
    cin >> v;
    sort(v.begin(), v.end());
    vector<string> ans;
    int c = 0;
    ans.pb(v);
    while (next_permutation(v.begin(), v.end()))
        ans.pb(v), c++;
    cout << ++c << endl;
    for (auto it : ans) {
        for (auto pre : it)
            cout << pre;
        cout << endl;
    }
    cout << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}