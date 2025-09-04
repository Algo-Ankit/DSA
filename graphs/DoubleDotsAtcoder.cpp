#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

vector<int> bfs(int start,vector<vector<int>> & adj,int n,vector<int> &signpost){
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
                signpost[v] = node; // Store the room that the signpost in Room v points to
                q.push(v);
            }
        }
    }
    return dist;
}

int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n + 1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }   
    vector<int>signpost(n + 1, 0); // signpost[i] will store the room that the signpost in Room i points to
    // If signpost[i] is 0 for i > 1, it means it was not reached.
    auto dist=bfs(1,adj,n,signpost);
    for(int i=2;i<=n;i++){
        if(dist[i]==1e9 || signpost[i]==0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<'\n';
    for(int i=2;i<=n;i++){
        cout<<signpost[i]<<'\n';
    }
    return 0;
}