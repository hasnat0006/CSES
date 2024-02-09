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

int maxVal = 1e6 + 1;
void solve() {
    int n, x;
    cin >> n;
    vector<int> freq(maxVal, 0);
    for (int i = 0; i < n; i++)
        cin >> x, freq[x]++;
    vector<int> multiples(maxVal, 0);
    for (int i = 1; i < maxVal; i++)
        for (int j = i; j < maxVal; j += i)
            if (freq[j])
                multiples[i] += freq[j];
    int ans = 0;
    for (int i = 0; i < maxVal; i++)
        if (multiples[i] > 1)
            ans = i;
    cout << ans << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
