#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N=305;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void dfs(int node,vector<int>& indexes){
    visited[node]= true;
    indexes.pb(node);
    for(int n:adj[node]){
        if(!visited[n]){
            dfs(n, indexes);
        }
    }
}

int main(){
    int n;cin>>n;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='1') adj[i].pb(j);
        }
    }
    
    // Find connected components and rearrange values
    for (int i = 1; i <= n; ++i) {
        if(!visited[i]){
            vector<int> indexes;
            dfs(i, indexes);

            vector<int> values;
            for(int ind:indexes){
                values.pb(p[ind]);
            }
            sort(values.begin(), values.end());
            sort(indexes.begin(), indexes.end());

            for(int j=0;j<indexes.size();j++){
                p[indexes[j]]= values[j];
            }
        }
    }
    // Print the final, prettiest permutation
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << " ";
    }
    cout << '\n';

    return 0;
}