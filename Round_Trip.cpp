//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
#include "debug.h"
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

map<int, vector<int>> adj;
map<int, int> visited, parent;
bool f = false;
int suru = -1;

void dfs(int start)
{
    visited[start] = 1;
    cout << start << " ";
    for (auto child : adj[start])
    {
        if (!visited[child])
        {
            dfs(child);
            parent[child] = start;
        }
        else if (child != parent[start])
        {
            f = true;
            suru = child;
            return;
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y), adj[y].pb(x);
    }
    dfs(1);
    if (!f)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    debug(suru);
    debug(parent);
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