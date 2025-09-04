#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const char move_char[4] = {'L', 'R', 'U', 'D'};

void monsters(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector<vector<int>> monster(n, vector<int>(m, -1));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    queue<array<int, 3>> q;
    int ax = -1, ay = -1;

    // Find monsters and A
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q.push({i, j, 0});
            } else if (grid[i][j] == 'A') {
                ax = i;
                ay = j;
            }
        }

    // BFS for monster movement
    while (!q.empty()) {
        auto [x, y, d] = q.front(); q.pop();
        if (monster[x][y] != -1) continue;
        monster[x][y] = d;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] != '#' && monster[nx][ny] == -1) {
                q.push({nx, ny, d + 1});
            }
        }
    }

    // BFS for player A
    queue<array<int, 3>> qa;
    qa.push({ax, ay, 0});
    dist[ax][ay] = 0;

    while (!qa.empty()) {
        auto [x, y, d] = qa.front(); qa.pop();

        if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
            // Reconstruct path
            string path;
            while (x != ax || y != ay) {
                int p = parent[x][y];
                path += move_char[p];
                x -= dx[p];
                y -= dy[p];
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << '\n' << path << '\n';
            return ;
        }

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                if (monster[nx][ny] == -1 || monster[nx][ny] > d + 1) {
                    dist[nx][ny] = d + 1;
                    parent[nx][ny] = k;
                    qa.push({nx, ny, d + 1});
                }
            }
        }
    }

    cout << "NO\n";
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    monsters();
    return 0;
    
}
