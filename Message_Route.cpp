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
map<int, int> level;
map<int, int> parent;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty())
    {
        int k = q.front();
        q.pop();
        for (auto child : adj[k])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                parent[child] = k;
                level[child] = level[k] + 1;
            }
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
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(1);
    if (!visited[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int ses = n;
    vector<int> ans;
    while (ses != 0)
    {
        ans.pb(ses);
        ses = parent[ses];
    }
    reverse(vf(ans));
    cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
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