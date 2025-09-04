#include <bits/stdc++.h>
using namespace std;

// Topological Sort using DFS
void dfs(int node,vector<int> &vis,stack<int> &st,vector<vector<int>> &adj){
    vis[node]=1;
    for(auto n:adj[node])
        if(!vis[n]) dfs(n,vis,st,adj);
    st.push(node);
}
vector<int> topodfs(int  v,vector<vector<int>> & adj){
    vector<int> vis(v,0);
    vector<int> topo;
    stack<int> st;
    
    for(int i=0;i<v;i++) if(!vis[i]) dfs(i,vis,st,adj);
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

// Topological sort using BFS also called Kahn's Algorithm
vector<int> topobfs(int v,vector<vector<int>> &adj){
    vector<int> indegree(v,0);
    queue<int> q;;
    vector<int> topo;

    for(int i=0;i<v;i++){
        for(auto node:adj[i]){
            indegree[node]++;
        }
    }
    for(int i=0;i<v;i++) if(indegree[i]==0) q.push(i);
    
    while(!q.empty()){
        int node = q.front();
        topo.push_back(node);
        q.pop();

        for(auto adjnode:adj[node]){
            indegree[adjnode]--;
            if(indegree[adjnode]==0) q.push(adjnode);
        }

        return topo;
    }

}

// Cycle detection in directed graph using topo sort Kahn's Algorithm
bool isCyclic(int v,vector<vector<int>> &adj){
    // if topo has n elements then its a DAG
    vector<int> topo = topobfs(v,adj);
    if(topo.size() != v) return true; // cycle detected
    return false; // no cycle detected
}

int main(){

}