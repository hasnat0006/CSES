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
    string s;
    cin >> s;
    int c = 0;
    vector<int> freq(27);
    for (int i = 0; i < s.length(); i++)
        freq[s[i] - 'A']++;
    int odd = 0, id = -1;
    for (int i = 0; i < 27; i++) {
        if (freq[i] % 2) {
            odd++;
            id = i;
        }
    }
    string ans1 = "", ans2 = "", final;
    if ((s.length() % 2 == 1 and odd > 1) or (s.length() % 2 == 0 and odd > 0))
        cout << "NO SOLUTION\n";
    else {
        for (int i = 0; i < 27; i++) {
            int x = freq[i] / 2;
            while (x--) {
                ans1 += i + 'A';
                ans2 += i + 'A';
            }
        }
        if (s.length() % 2 == 1)
            ans1 += id + 'A';
        reverse(ans2.begin(), ans2.end());
        final = ans1 + ans2;
        cout << final << endl;
    }
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}