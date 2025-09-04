#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL); 

const int N=105;
const int K=1e5+5;
const int MOD=1e9+7;
int n,a[N];
vector<vector<int>> dp(N,vector<int>(K,-1));
int k;

int rec(int i,int left){
    if(left<0) return 0;
    if(i>n) return (left==0);
    if(dp[i][left]!=-1) return dp[i][left];
    int ways = 0;
    for (int j = 0; j <= a[i]; j++) {
        if (left - j >= 0)
            ways = (ways + rec(i + 1, left - j)) % MOD;
    }

    return dp[i][left]=ways;
}
int main(){
    cin>>n;
    cin>>k;
    for(int i=1;i<n;i++)cin>>a[i];

    cout<<rec(1,k);
}