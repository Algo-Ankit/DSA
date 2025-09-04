#include <bits/stdc++.h>
using namespace std;    
#define ll long long
#define pb push_back

vector<int> bfs(int start,vector<vector<int>> &adj, int n){
    vector<int> dist(n+1,1e9);
    queue<int> q;
    dist[start]=0;
    q.push(start);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto v:adj[node]){
            if(dist[v]==1e9){
                dist[v]=dist[node]+1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;

    for(int i=0;i<m;++i){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    int s0, t0, l0;
    int s1, t1, l1;
    cin >> s0 >> t0 >> l0;
    cin >> s1 >> t1 >> l1;

    vector<int> d0= bfs(s0, adj, n);
    vector<int> d1= bfs(s1, adj, n);
    vector<int> r0= bfs(t0, adj, n);
    vector<int> r1= bfs(t1, adj, n);

    int ans = -1;

    // Case 1: If the paths are already non intersecting
    if(d0[t0]<=l0 && d1[t1]<=l1) ans=m-(d0[t0] + d1[t1]);

    // Case 2: If the paths intersect at some point
    for(int i=1;i<=n;++i){

        auto di=bfs(i, adj, n); // stores the dist. from node i to all other nodes
        for(int j=1;j<=n;++j){
            int dij=di[j];

            if (d0[i] == 1e9 || r0[j] == 1e9 || d1[i] == 1e9 || r1[j] == 1e9 || dij == 1e9) continue;

            //check 1st orientation from s to t
            int a1=d0[i]+dij+r0[j];
            int a2=d1[i]+dij+r1[j];
            if(a1<=l0 && a2<=l1) ans=max(ans, m-(a1+a2-dij));

            //check 2nd orientation from t to s
            a1=r0[i]+dij+d0[j];
            if(a1<=l0 && a2<=l1) ans=max(ans, m-(a1+a2-dij));
        }

    }
    cout << ans << endl;
    return 0;
}