#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define wh while (!q.empty())
static const int dx[] = {0, 0, -1, 1}; // right, left, up, down
static const int dy[] = {1, -1, 0, 0}; // right, left, up, down
// Q1
void countingRooms()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                if (!visited[i][j])
                {
                    roomCount++;
                    // BFS to explore the room
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty())
                    {

                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++)
                        {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !visited[nx][ny])
                            {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }
    cout << roomCount << "\n";
}

// Q2
void labyrinth()
{
    // Inputs and vector initialization
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    // BFS to find the path from A to B
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;
    wh
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        rep(i, 0, 4)
        {
            int nr = x + dx[i];
            int nc = y + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && visited[nr][nc] != 1)
            {
                if (grid[nr][nc] == '.' || grid[nr][nc] == 'B')
                {
                    visited[nr][nc] = 1;
                    parent[nr][nc] = {x, y}; // Store the parent
                    q.push({nr, nc});
                }
            }
        }
    }
    if (visited[end.first][end.second] != 1)
        cout << "NO\n";
    else
    {
        string path = "";
        pair<int, int> current = end;
        while (current != start)
        {
            pair<int, int> prev = parent[current.first][current.second];

            if (prev.first == -1 && prev.second == -1)
            {
                // Fail-safe: Parent not found — corrupted path
                cout << "NO\n";
                return;
            }

            if (prev.first < current.first)
                path += 'D'; // Down
            else if (prev.first > current.first)
                path += 'U'; // Up
            else if (prev.second < current.second)
                path += 'R'; // Right
            else if (prev.second > current.second)
                path += 'L'; // Left
            current = prev;
        }
        reverse(all(path)); // Reverse the path to get from A to B
        cout << "YES\n"
             << path.length() << "\n"
             << path << "\n";
    }
}

void bfs(vector<vector<int>> &adj, vector<ll> &dist, vector<int> &parent, int start)
{

    dist[start] = 0;
    parent[start] = -1;
    queue<int> q;
    q.push(start);
    wh
    {
        int node = q.front();
        q.pop();
        for (int n : adj[node])
        {
            if (dist[n] == LLONG_MAX)
            {
                dist[n] = dist[node] + 1;
                parent[n] = node;
                q.push(n);
            }
        }
    }
    return;
}

// Q4
void messageRoute()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);

    bfs(adj, dist, parent, 1);

    if (dist[n] == LLONG_MAX)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    else
    {
        vector<int> path;
        int curr = n;
        while (curr != -1)
        {
            path.pb(curr);
            curr = parent[curr];
        }
        reverse(all(path));
        cout << path.size() << "\n";
        for (int i = 0; i < (int)path.size(); i++)
            cout << path[i] << " ";
    }
}

//Q5
void bfs2( vector<vector<int>> &adj, vector<int> &teams, vector<bool> &visited , int start) {
    queue<int> q;
    q.push(start);
    teams[start] = 0; // Assign team 0 to the first node
    visited[start] = true;
    wh{
        int node= q.front();
        q.pop();

        for(int n:adj[node]){
            if(!visited[n]){
                visited[n]= true;
                teams[n] = 1 - teams[node]; // Assign opposite team
                q.push(n);
            }
            else if (teams[n] == teams[node]) {
                // Conflict: same team adjacent
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
}
void buildingTeams(){
    int n,m;cin>>n>>m;
    vector<vector<int>> adj(n+1);
    rep(i,0,m){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> teams(n+1, -1); // -1 means unassigned
    vector<bool> visited(n+1, false);

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            bfs2(adj, teams, visited, i);
        }
    }

    for(int i=1;i<=n;i++){
        if(teams[i]==0){
            // convert it to 2
            teams[i] = 2;
        }
        else if(teams[i]==-1){
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for(int i=1;i<=n;i++) cout << teams[i] << " ";

}


int main()
{
    fast_io;

    buildingTeams();
    return 0;
}