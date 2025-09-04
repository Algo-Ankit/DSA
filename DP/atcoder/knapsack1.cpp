#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // form
    int n, W;
    cin>>n>>W;
    vector<int> w(n+1),v(n+1);
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j]=dp[i-1][j]; // Not taking the i-th item
            if(j>=w[i]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]); // Taking the i-th item
            }
        }
    }
    cout<<dp[n][W]<<endl; // Maximum value that can be obtained with weight limit W
    return 0;
}