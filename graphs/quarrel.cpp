#include <bits/stdc++.h> 
using namespace std;

const int MAXN = 501;

// dist[bob_pos][alex_pos] = min_time
// Initialized to -1 (unvisited) by default for global arrays, but explicit initialization is safer.
int dist[MAXN][MAXN]; 
// parent[bob_pos][alex_pos] = {prev_bob_pos, prev_alex_pos}
pair<int, int> parent[MAXN][MAXN]; 

// Adjacency list for the graph
vector<int> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;

    // Starting state: Bob at 1, Alex at n, time 0
    dist[1][n] = 0;
    q.push({1, n});

    int final_k = -1; // Stores the minimum time (length of routes)

    // BFS loop
    while (!q.empty()) {
        pair<int, int> current_state = q.front();
        q.pop();

        int bob_curr = current_state.first;
        int alex_curr = current_state.second;
        int current_time = dist[bob_curr][alex_curr];

        // If we reached the destination (Bob at n, Alex at 1)
        if (bob_curr == n && alex_curr == 1) {
            final_k = current_time; // This is the shortest time
            break; // Found the shortest path, no need to explore further
        }

        for (int bob_next : adj[bob_curr]) {
            for (int alex_next : adj[alex_curr]) {
               
                if (bob_next == alex_next) continue; // Collision, skip this pair of moves

                // If this new combined state (bob_next, alex_next) hasn't been visited yet
                if (dist[bob_next][alex_next] == -1) {
                    dist[bob_next][alex_next] = current_time + 1; // Update distance
                    parent[bob_next][alex_next] = {bob_curr, alex_curr}; // Store parent for path reconstruction
                    q.push({bob_next, alex_next}); // Enqueue the new state
                }
            }
        }
    }

    // Output results
    if (final_k == -1) {
        cout << -1 << endl; // No valid routes found
    } else {
        cout << final_k << endl;

        vector<int> bob_path;
        vector<int> alex_path;

        int curr_bob_pos = n;
        int curr_alex_pos = 1;
        // Backtrack using the parent array until we reach the starting state (1, n)
        while (curr_bob_pos != 1 || curr_alex_pos != n) {
            bob_path.push_back(curr_bob_pos);
            alex_path.push_back(curr_alex_pos);
            
            pair<int, int> prev_pos = parent[curr_bob_pos][curr_alex_pos];
            curr_bob_pos = prev_pos.first;
            curr_alex_pos = prev_pos.second;
        }
        // Add the initial positions to the paths
        bob_path.push_back(1);
        alex_path.push_back(n);

        // Paths were built in reverse order, so print them by iterating backwards
        for (int i = bob_path.size() - 1; i >= 0; --i) {
            cout << bob_path[i] << (i == 0 ? "" : " ");
        }
        cout << endl;

        for (int i = alex_path.size() - 1; i >= 0; --i) {
            cout << alex_path[i] << (i == 0 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}