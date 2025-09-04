#include <bits/stdc++.h>
using namespace std;

// DIJKSTRA'S ALGORITHM -> USing Min-Heap Priority Queue
vector<int> dijkstraPq(int V, vector<vector<pair<int, int>>> &adj, int S)
{

    // Min-heap priority queue: (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    vector<int> dist(V, 1e9);
    dist[S] = 0; // Distance to source is 0

    while (!pq.empty())
    {
        int dis = pq.top().first;   // Current distance
        int node = pq.top().second; // Current node
        pq.pop();
        for (auto it : adj[node])
        {
            int adjnode = it.first; // Adjacent node
            int edgewt = it.second; // Weight of the edge
            if (dis + edgewt < dist[adjnode])
            {
                dist[adjnode] = dis + edgewt;
                pq.push({dist[adjnode], adjnode}); // Push updated distance to the queue
            }
        }
    }
    return dist; // Return the distance array
}

// DIJKSTRA'S ALGORITHM -> Using Set
vector<int> dijkstraSet(int V, vector<vector<pair<int, int>>> &adj, int S)
{

    // Set to store (distance, node) pairs
    set<pair<int, int>> st;
    st.insert({0, S});

    vector<int> dist(V, 1e9);
    dist[S] = 0; // Distance to source is 0

    while (!st.empty())
    {
        auto [dis, node] = *st.begin(); // Get the node with the minimum distance
        st.erase(st.begin());           // Remove it from the set
        for (auto [adjnode,wt] : adj[node])
        {
            if(dis+wt<dist[adjnode]){
                if(dist[adjnode]!=1e9){
                    st.erase({dist[adjnode], adjnode}); // Remove the old distance
                }
            }
            dist[adjnode]=dis+wt; // Update the distance
            st.insert({dist[adjnode], adjnode}); // Insert the new distance

        }
    }
    return dist; // Return the distance array
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}