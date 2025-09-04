#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define INF 1e9
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int shortestPath(vector<vector<int>> &maze,vector<int> &start,vector<int> &end){
    int n= maze.size();
    int m=maze[0].size();

    int steps=0;
    vector<int> dx= {1,-1,0,0};
    vector<int> dy= {0,0,1,-1};
    vector<vector<int>> dist(n, vector<int>(m, INF));
    dist[start[0]][start[1]] = 0;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;

    pq.push({0,start[0],start[1]});

    while(!pq.empty()){
        auto [d,x,y]= pq.top();
        pq.pop();
        if(dist[x][y]<d) continue;

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            while(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]==0){
                steps++; 
                nx+=dx[i];
                ny+=dy[i];
            }
            if(d+steps<dist[nx][ny]){
                dist[nx][ny] = d + steps;
                pq.push({dist[nx][ny], nx, ny});
            }
        }
    }
    if(dist[end[0]][end[1]] == INF) return -1; // If the end is unreachable
    return dist[end[0]][end[1]]; // Return the shortest path distance to

}

int main(){

}