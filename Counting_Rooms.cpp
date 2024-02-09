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

vector<pair<int, int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[1001][1001];

bool isValid(int x, int y, int n, int m) {
    if (x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (visited[x][y])
        return false;
    return true;
}

void dfs(int x, int y, int n, int m) {
    visited[x][y] = true;
    for (auto i : moves) {
        if (isValid(x + i.first, i.second + y, n, m))
            dfs(x + i.first, y + i.second, n, m);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#')
                visited[i][j] = true;
            else
                visited[i][j] = false;
        }
    }
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j, n, m);
                rooms++;
            }
        }
    }
    // debug(moves);
    cout << rooms << endl;
}

int32_t main() {
    YUSUF REZA HASNAT;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}