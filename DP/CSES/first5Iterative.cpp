#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


void bookshop(){
    int n, x;
    cin >> n >> x;
    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    for (int i = 0; i < n; ++i) cin >> pages[i];

    // dp[b] = max total pages we can get with budget b
    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int b = x; b >= prices[i]; --b) {
            dp[b] = max(dp[b], dp[b - prices[i]] + pages[i]);
        }
    }

    cout << dp[x] << "\n";
}

void gridpaths1(){
    int n;cin>>n;
    int dp[1007][1007];
    static int mod=1e9+7;
    vector<string> grid(n+1);
    for(int i=0;i<n;i++) cin >> grid[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='*') dp[i][j]=0;
            else if(i==0 && j==0) dp[i][j]=1;
            else{
                dp[i][j]=0;
                if(i>0) dp[i][j] += dp[i-1][j];
                if(j>0) dp[i][j] += dp[i][j-1];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n-1][n-1] << "\n";

}

set<int> getdigits(int n){
    set<int> digits;
    while(n){
        digits.insert(n%10);
        n /= 10;    
    }
    return digits;
}
void removingdigits(){
    int n;cin>>n;
    vector<int> dp(n+1,1e9);
    dp[0]=0;
    for(int i=0;i<=n;i++){
        set<int> digits=getdigits(i);
        for(auto d:digits){
            if(i-d>=0)dp[i]=min(dp[i],1+dp[i-d]);
        }
    }
    cout << dp[n] << "\n";
}

void coincomb1(){
    int n,x; cin >> n >> x; 
    vector<int> coins(n);
    int mod=1e9+7;
    for(int i=0;i<n;i++) cin >> coins[i];
    vector<ll> dp(x+1,0);
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(coins[j]<=i) dp[i]=(dp[i]+dp[i-coins[j]])%mod;
        }
    }
    cout << dp[x]<< "\n";
}

void dicecomb(){
    vector<ll> dp(1000001, 0);
    static int mod=1000000007;
    int n;cin>>n;
    for(int i=0;i<=n;i++){
        if(i==0) dp[i]=1;
        else dp[i]=0;
        for(int j=1;j<=6;j++){
            if(j<=i) dp[i] += dp[i-j];
        }
        dp[i] %= mod;
    }
    cout<<dp[n]<<"\n";
}

int main(){
    fast_io;
    
    bookshop();
    return 0;
}