#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

vector<int> comp;
const int N = 1e5 + 5;
int dp[N], visited[N];
void dfs(int node, vector<vector<int>> &adj)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
            dfs(it, adj);
    }
    comp.pb(node);
}

void topological_sort(vector<vector<int>> &adj, int n)
{
    comp.clear();
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, adj);
    }
    reverse(comp.begin(), comp.end());
}

int main()
{
    fast_io;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    topological_sort(adj, n);

    for (int x : comp)
    {
        for (auto it : adj[x])
        {
            dp[it] = max(dp[it], dp[x] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}