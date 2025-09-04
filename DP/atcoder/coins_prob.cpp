#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);     
int n;
const int N=310;
double dp[N][N][N];
int visited[N][N][N];

double rec(int c1,int c2,int c3){
    if(c1==0 && c2==0 && c3==0) return 0;
    if(visited[c1][c2][c3]) return dp[c1][c2][c3];
    visited[c1][c2][c3]=1;
    int ans=dp[c1][c2][c3];
    ans=1;
    
    

}
int main(){
    cin>>n;
    vector<int> count(4);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        count[x]++;
    }
    printf("%0.10f\n",rec(count[1], count[2], count[3]));
}