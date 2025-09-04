#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fr(i,a,b) for(int i = a; i < b; ++i)

vector<vector<pair<int,long long>>> adj;
vector<long long> dist;

vector<long long> dijkstraPq(int V, vector<vector<pair<int, long long>>> &adj, int S)
{
    // Min-heap priority queue: (distance, node)
    priority_queue<pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>> pq;

    pq.push({0, S});

    dist.assign(V, LLONG_MAX);
    dist[S] = 0; // Distance to source is 0

    while (!pq.empty())
    {
        // ✅ changed from int to long long
        long long dis = pq.top().first;   // Current distance
        int node = pq.top().second; // Current node
        pq.pop();
        if(dis > dist[node]) continue; // Skip outdated entries

        for (auto it : adj[node])
        {
            int adjnode = it.first;          // Adjacent node
            long long edgewt = it.second;    //  from int to long long

            if (dis + edgewt < dist[adjnode])
            {
                dist[adjnode] = dis + edgewt;
                pq.push({dist[adjnode], adjnode}); // Push updated distance to the queue
            }
        }
    }
    return dist; // Return the distance array
}
void shortestpaths1(){
    int n,m; cin>>n>>m;
    adj.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;               // : weight is long long
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dijkstraPq(n+1, adj, 1); // Assuming source is node 1
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == LLONG_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    
}
