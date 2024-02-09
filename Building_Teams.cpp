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

map<int, vector<int>> adj;
map<int, int> visited;
map<int, int> color;
int f = 0;

bool dfs(int start, int clr) {
    color[start] = clr, visited[start] = 1;
    for (auto child : adj[start]) {
        if (!visited[child]) {
            if (!dfs(child, clr ^ 1))
                return false;
        }
        else if (color[child] == color[start])
            return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> team;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    // debug(adj);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (!dfs(i, 0)) {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }
    for (auto it : color)
        cout << it.second + 1 << " ";
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