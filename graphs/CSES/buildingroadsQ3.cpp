#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU{
public:
    vector<int> rank,parent,size;
    DSU(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++) parent[i] = i;
    }
    int findParent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionbyRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return; // u and V are already in same component
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pu]>rank[pv]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void unionbySize(int  u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return ; // u and V are already in same component
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu] += size[pv];
        }

    }
};

//Building Roads
void buuildingroads(){
     int n, m;
    cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unionbySize(u, v);
    }

    vector<int> reps;
    for (int i = 1; i <= n; ++i) {
        if (dsu.findParent(i) == i) reps.push_back(i);
    }

    cout << reps.size() - 1 << "\n";
    for (int i = 1; i < (int)reps.size(); ++i) {
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }

}

// Message Route
void messageroute(){
    int n,m;cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<n;i++){
        int u,v;cin>>u>>v;
        dsu.unionbySize(u,v);
    }
    if(dsu.findParent(1)!=dsu.findParent(n)){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    else{
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

   
    return 0; 
}
