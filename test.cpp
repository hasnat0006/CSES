#include <bits/stdc++.h>
using namespace std;
#define ll int
#define float double
const ll N = 1005;
ll m, n;
pair<ll, ll> s, e;
ll vis[N][N];
char des[N][N];
// map<pair<ll, ll>, ll> vis;
map<pair<ll, ll>, pair<ll, ll>> par;
char ke_koi_theke_asche(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
    {
        if (a.second < b.second)
        {
            return 'L';
        }
        else
        {
            return 'R';
        }
    }
    else
    {
        if (a.first < b.first)
        {
            return 'U';
        }
        else
        {
            return 'D';
        }
    }
}
ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};
bool valid(ll x, ll y)
{
    return (x > 0 and y > 0 and x <= m and y <= n);
}
void bfs(pair<ll, ll> a)
{
    queue<pair<ll, ll>> q;
    q.push(a);
    vis[a.first][a.second] = 1;
    while (!q.empty())
    {
        pair<ll, ll> z = q.front();
        q.pop();
        ll x = z.first, y = z.second;
        for (ll i = 0; i < 4; ++i)
        {
            ll tx = x + dx[i];
            ll ty = y + dy[i];
            // cout<<tx<<" "<<ty<<endl;
            if (valid(tx, ty) and !vis[tx][ty])
            {
                par[{tx, ty}] = z;
                q.push({tx, ty});
                vis[tx][ty] = 1;
                des[tx][ty] = ke_koi_theke_asche({tx, ty}, z);
                if (tx == e.first and ty == e.second)
                    return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t = 1, CT = 0;
    // cin >> t;
    // cin.ignore();
    while (t--)
    {
        cin >> m >> n;
        char x;
        for (ll i = 1; i <= m; ++i)
        {
            for (ll j = 1; j <= n; ++j)
            {
                cin >> x;
                if (x == 'A')
                {
                    s = {i, j};
                }
                else if (x == 'B')
                {
                    e = {i, j};
                }
                else if (x == '#')
                    vis[i][j] = 1;
            }
        }
        // cout<<e.first<<" "<<e.second<<endl;
        bfs(s);
        // for(auto it:par)
        // {
        //     cout<<"{"<<it.first.first<<","<<it.first.second<<"} -> "<<"{"<<it.second.first<<","<<it.second.second<<"}\n";
        // }
        if (!vis[e.first][e.second])
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            vector<char> st;
            while (e != s)
            {
                st.push_back(des[e.first][e.second]);
                e = par[e];
            }
            ll n = st.size();
            cout << st.size() << "\n";
            for (ll i = n - 1; i >= 0; --i)
            {
                cout << st[i];
            }
            cout << "\n";
        }
    }
    return 0;
}