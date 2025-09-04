#include <bits/stdc++.h>
using namespace std;   
#define ll long long
#define pb push_back

class DSU{
public:
    vector<int> rank,parent,size;
    DSU(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
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

int main(){
    int n,m,k;cin>>n>>m>>k;
    // Storing Edges ->(in a set to avoid duplicates)
    set<pair<int, int>> edge_set;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edge_set.insert({u, v});
    }

    // Storing Operations
    vector<pair<string, pair<int, int>>> ops(k);
    vector<pair<int, int>> added_edges;
    for (int i = 0; i < k; ++i) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        if (u > v) swap(u, v);
        ops[i] = {op, {u, v}};
        if (op == "cut") {
            edge_set.erase({u, v}); // remove from initial set
        }
    }

    DSU dsu(n);

    vector<string> answers;
    // Add remaining (not cut) edges first -> final graph connected components after operations
    for (auto &[u, v] : edge_set) {
        dsu.unionbyRank(u, v); 
    }
    // Process operations in reverse order
    for(int i=k-1;i>=0;i++){
        auto [op,edge]= ops[i];
        int u = edge.first, v = edge.second;
        if(op=="ask"){
            if(dsu.findParent(u)==dsu.findParent(v)) answers.pb("YES");
            else answers.pb("NO");
        }
        else if(op=="cut") dsu.unionbySize(u,v);
    }
    reverse(answers.begin(), answers.end());
    for (auto &ans : answers)
        cout << ans << "\n";

    return 0;

}