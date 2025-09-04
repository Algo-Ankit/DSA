#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define rep(i, a, b) for (int i = (a); i < (b);i++)

// cycle detection in undirected graph
vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
bool is_cycle = false;
void dfs(int node, int par){
    visited[node] = true;
    parent[node] = par;
    for(int n:adj[node]){
        if(n==par) continue; // skip the parent node
        else if(visited[n]){
            // if the node is already visited and not the parent, then we have a cycle
            is_cycle = true;
            vector<ll> path;
            ll current = node;
            path.pb(current);
            while(current != n){
                current = parent[current];
                path.pb(current);
            }
            path.pb(node);
            reverse(all(path));
            cout << path.size() << "\n";
            for(ll i=0;i<(int)path.size();i++)cout << path[i] << " ";
            exit(0);
        }else{
            dfs(n, node); // visit the node
        }
    }
}
void roundTrip(){
    int n,m;cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1, false);
    parent.resize(n+1, -1);
    rep(i,0,m){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    rep(i,1,n+1){
        if(!visited[i] && !is_cycle){
            dfs(i,-1); //(node,parent)
        }
    }

    if(!is_cycle){
        cout << "IMPOSSIBLE\n";
        return;
    }
}

int main(){
    fast_io;
    // Q6
    roundTrip();
    return 0;
}