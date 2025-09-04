#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int INF = 1e9 + 7;
const int MAXN = 1001;

struct Edge {
    int to;
    char character;
};
vector<vector<Edge>> adj(MAXN);
int dist[MAXN][MAXN];

int bfs(int N,int M){
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    dist[1][N]=0;
    q.push({1, N});

    int min_pall_length = INF;
    while (!q.empty()) {
        pair<int,int> curr= q.front();
        q.pop();
        int u = curr.first;
        int v = curr.second;
        int d = dist[u][v];

        // -- Checking the current state if it can form a pallindrome or final answer --
        // Candidate 1: Even length palindrome.
        if(u==v) {
            min_pall_length = min(min_pall_length, 2*d);
        }
        // Candidate 2: Odd length palindrome.
        for(const Edge &edge:adj[u]){
            if(edge.to==v)  min_pall_length = min(min_pall_length, 2 * d + 1);
        }
        // pruning: If the current distance is already greater than the minimum found, skip further processing.
        // Skip further expansion from this state and move to the next in the queue.
        if (d * 2 >= min_pall_length && (d * 2 + 1) >= min_pall_length) {
            continue; 
        }

        // -- Expanding the BFS from the current state --
        for( auto edge:adj[u]){
            int next_u=edge.to;
            char char_a= edge.character;

            for(auto edgev:adj[v]){
                int next_v=edgev.to;
                char char_b=edgev.character;

                // condition for pallindrome formation
                if(char_a==char_b){
                    if(dist[next_u][next_v]==-1 || dist[next_u][next_v]>d+1){
                        dist[next_u][next_v] = d + 1;
                        q.push({next_u, next_v});
                    }
                }
            }
        }


    }
    return (min_pall_length == INF) ? -1 : min_pall_length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; // N: number of vertices, M: number of edges
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c}); // Add edge for the reverse direction
    }
    int result = bfs(N, M);
    cout << result << endl;
    return 0;
}