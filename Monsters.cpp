//!-----------------------------------------------------!//
//!                  YUSUF REZA HASNAT                  !//
//!-----------------------------------------------------!//

#include <bits/stdc++.h>
// #include "debug.h"
using namespace std;

// #define int long long
// #define float long double
#define pb push_back
#define pairi pair<int, int>
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define YUSUF ios_base::sync_with_stdio(false),
#define REZA cin.tie(NULL),
#define HASNAT cout.tie(NULL)

int mod = 1001000007;
float pi = 3.141592653589793238462643383279502884197;
// int inf = 1e18;

int n, m;
pairi st, ed = {1001, 1001};
int visited[1001][1001];
char des[1001][1001];
map<pairi, pairi> parent;
vector<pairi> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y) { return (x >= 0 and x < n and y >= 0 and y < m); }

char jabe(pairi a, pairi b) {
    int x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second;
    if (x1 == x2) {
        if (y1 > y2)
            return 'R';
        return 'L';
    }
    else if (y1 == y2) {
        if (x1 > x2)
            return 'D';
        return 'U';
    }
}

bool isCorner(int x, int y) {
    if (x == n - 1 or y == m - 1)
        return true;
    return false;
}

void bfs(pairi start) {
    queue<pairi> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    while (!q.empty()) {
        pairi k = q.front();
        q.pop();
        for (auto it : moves) {
            int x = k.first + it.first;
            int y = k.second + it.second;
            if (isValid(x, y) and !visited[x][y]) {
                visited[x][y] = 1;
                des[x][y] = jabe({x, y}, k);
                q.push({x, y});
                parent[{x, y}] = k;
                if (isCorner(x, y)) {
                    ed = {x, y};
                    return;
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    char x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            if (x == '#' or x == 'M')
                visited[i][j] = 2;
            else if (x == 'A')
                st = {i, j};
        }
    }
    bfs(st);
    if (!visited[ed.first][ed.second]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<char> ans;
    while (ed != st) {
        ans.pb(des[ed.first][ed.second]);
        ed = parent[ed];
    }
    cout << ans.size() << endl;
    int n = ans.size();
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i];
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