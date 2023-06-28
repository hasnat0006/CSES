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

void build(int ti, int low, int high, vector<int> &v, vector<int> &seg)
{
    if (high == low)
    {
        seg[ti] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ti + 1, low, mid, v, seg);
    build(2 * ti + 2, mid + 1, high, v, seg);
    seg[ti] = seg[2 * ti + 1] + seg[ti * 2 + 2];
}
int find(int tl, int tr, int ql, int qr, int ti, vector<int> &v, vector<int> &seg)
{
    if (tl > qr or tr < ql)
        return 0;
    if (tl >= ql and tr <= qr)
        return seg[ti];
    int mid = (tl + tr) / 2;
    int l = find(tl, mid, ql, qr, 2 * ti + 1, v, seg);
    int r = find(mid + 1, tr, ql, qr, 2 * ti + 2, v, seg);
    return l + r;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), seg(4 * n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build(0, 0, n - 1, v, seg);
    // debug(v);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << find(0, n - 1, l - 1, r - 1, 0, v, seg) << endl;
    }
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