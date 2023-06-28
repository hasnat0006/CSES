//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
using namespace std;
// #include "debug.h"
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
int sz = 2 * 1e5 + 5;
vector<int> v(sz), seg(4 * sz);
void update(int ti, int low, int high, int id, int val)
{
    if (id > high or id < low)
        return;
    if (id == high and high == low)
    {
        seg[ti] = val;
        return;
    }
    int mid = (low + high) / 2;
    update(2 * ti + 1, low, mid, id, val);
    update(2 * ti + 2, mid + 1, high, id, val);
    seg[ti] = (seg[2 * ti + 1] + seg[ti * 2 + 2]);
}
void build(int ti, int low, int high)
{
    if (high == low)
    {
        seg[ti] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ti + 1, low, mid);
    build(2 * ti + 2, mid + 1, high);
    seg[ti] = (seg[2 * ti + 1] + seg[ti * 2 + 2]);
}
int find(int tl, int tr, int ql, int qr, int ti)
{
    if (tl > qr or tr < ql)
        return 0;
    if (tl >= ql and tr <= qr)
        return seg[ti];
    int mid = (tl + tr) / 2;
    int l = find(tl, mid, ql, qr, 2 * ti + 1);
    int r = find(mid + 1, tr, ql, qr, 2 * ti + 2);
    return (l + r);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build(0, 0, n - 1);
    while (q--)
    {
        int x, l, r;
        cin >> x >> l >> r;
        if (x == 2)
            cout << find(0, n - 1, l - 1, r - 1, 0) << endl;
        else
            // void update(int ti, int low, int high, int id, int val)
            update(0, 0, n - 1, l - 1, r);
        // debug(seg);
    }
}

int32_t main()
{
    YUSUF REZA HASNAT;
    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}