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

using namespace std;

int binaryExponentiation(int base, int power) {
    int ans = 1;
    while (power) {
        if (power % 2 == 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return ans;
}
void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0 and b == 0)
        cout << "1\n";
    else
        cout << binaryExponentiation(a, b) << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
