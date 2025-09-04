#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define INF 1e9
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

void dfs(int node, vector<int> &vis, vector<vector<pair<int,int>>> &adj, stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        int v = it.first;
        if (vis[v] == 0) dfs(v, vis, adj, st);
    }
    st.push(node);
}

vector<int> shortestPathTopo(int n, int m, vector<pair<int, pair<int, int>>> &edges) {
    vector<vector<pair<int,int>>> adj(n);
    vector<int> indegree(n,0);

    for(int i=0;i<n;i++){
        int u = edges[i].first;
        int v = edges[i].second.first;
        int w = edges[i].second.second;
        adj[u].pb({v, w});
        indegree[v]++;
    }
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(vis[i]==0) dfs(i, vis, adj, st);
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        for(auto [it,wt]:adj[node]){
            if(dist[node]+wt<dist[it]){
                dist[it]=dist[node]+wt;
            }
        }
    }
    return dist; // Return the shortest path distances from the source node
}

int main(){
    fast_io;
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, {v, w}};
    }
    vector<int> result = shortestPathTopo(n, m, edges);
    for(auto &x: result) {
        if(x == INF) cout << "INF ";
        else cout << x << " ";  
    }
    cout << endl;
    return 0;
}