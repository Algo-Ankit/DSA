#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL); 

// Solving the DAG Question wihout using Topological Sort ot DFS or BFS -> Purely using DP
const int MOD = 1e9 + 7;

int main(){
    int h,w;
    cin>> h >> w;
    vector<vector<char>> grid(h+1,vector<char>(w+1,0));
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(h+1,vector<int>(w+1,0));
     dp[1][1] = (grid[1][1] == '.') ? 1 : 0; // base case only if cell is not blocked
    // dp[i][j] = returns the maximum number of paths from (1,1) to reach (i,j) -> paths from (1,1) ending at(i,j)
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j]=='#') continue; // if the cell is blocked, then we cannot reach there
            if(i == 1 && j == 1) continue; //Skip the base cell
            else{
                if(i>1) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
                if(j>1) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[h][w]<<endl; // the answer is the number of paths from (1,1) to (h,w)
    return 0;

}