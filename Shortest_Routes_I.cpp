//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
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

typedef pair<int, pair<int, int>> pairUV;

// vector<pair<int, int>> adj[10005];
map<int, bool> visited;
map<int, int> parent;
map<int, vector<pair<int, int>>> adj;

void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        int wt;
        std::cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    int sum = 0, c = 0;
    vector<pairUV> ans;
    priority_queue<pairUV, vector<pairUV>, greater<pairUV>> pq;
    pq.push({0, {1, -1}});
    while (!pq.empty()) {
        pairUV k = pq.top();
        pq.pop();
        int u = k.second.first;
        int v = k.second.second;
        int wt = k.first;
        if (visited[u])
            continue;
        else
            c++;
        sum += wt;
        visited[u] = 1;
        if (v != -1)
            ans.push_back({u, {v, wt}});
        for (auto it : adj[u]) {
            int adjNode = it.first;
            int adjwt = it.second;
            if (!visited[adjNode])
                pq.push({adjwt, {adjNode, u}});
        }
    }
    debug(parent);
    sort(vf(ans));
    for (auto it : ans)
        std::cout << it.first << " " << it.second.first << " -> "
                  << it.second.second << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}