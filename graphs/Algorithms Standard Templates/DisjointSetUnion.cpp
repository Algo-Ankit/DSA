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
        for(int i=0;i<n;i++) parent[i] = i;
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

// Kruskal's algorithm to find minimum spanning tree
int MST(int v,vector<vector<pair<int,int>>> & adj){
    // Make a list of all edges
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int u = i;
            int w = it.first;
            int v = it.second;
            edges.push_back({w,{u,v}});
        }
    }
    sort(edges.begin(),edges.end());
    DSU dsu(v);

    int mstwt=0;
    for(auto [wt,uv]:edges){
        int u=uv.first; int v=uv.second;
        if(dsu.findParent(u)!=dsu.findParent(v)){
            dsu.unionbySize(u,v);
            mstwt += wt;
        }
    }
    return mstwt; // The weight of the minimum spanning tree-> Wt of all edges in MST
}
