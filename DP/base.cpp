#include <bits/stdc++.h>
using namespace std;
/*int s[1001];
int t[1001];
int x,k;
int n;
int dp[1001][1001][1001];
  
    Question 1
int rec(int level,int time_taken,int item_taken){
    //max skill i can make from [level to n-1] if[0 to level ] is decided and parameters from [level to n-1
    // level -> current item in 1 to n-1.
    // pruning

    // base case
    if(level == n) return 0;
    // cache check
    if(dp[level][time_taken][item_taken] != -1){
        return dp[level][time_taken][item_taken];
    }
    //compute
    int ans=rec(level+1,time_taken,item_taken);
    if(time_taken+t[level] <=x && item_taken+1<=k){
        ans=min(ans,rec(level+1,time_taken+t[level],item_taken+1)+s[level]);
    }
    // save and return
    return dp[level][time_taken][item_taken]=ans;
}
    */

int n;
int x[101]; //as N<=100
int t;
int dp[101][10001]; // as t<=10000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

}
int rec(int level,int sum){
    // pruning 
    if(sum>t) return 0;
    // base case
    if(level==n+1){
        if(sum==t) return 1;
        else return 0;
    }
    // cache check
    if(dp[level][sum]!=-1) return dp[level][sum];
    // computation
    int ans=0;
    if(rec(level+1,sum)==1) ans=1; // not take
    else if(rec(level+1,sum+x[level])==1) ans=1; // take
    // save and return
    return dp[level][sum]=ans;

}

// Question 3 
int dparr[105][10100];
void solve(){
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    memset(dparr,-1,sizeof(dparr));
    dp3(1,0);
}
int dp3(int level,int left){
    //pruning
    if(left<0) return 0;
    // base case
    if(level==n+1){
        if(left==0) return 1;
        else return 0;
    }
    //cache check
    if(dparr[level][left]!=-1) return dparr[level][left];
    // computation
    int ans=0;
    if(rec(level+1,left)==1) ans=1;
    else if(rec(level+1,left-x[level])==1) ans=1;
    // save and return
    ans=dparr[level][left];
    return ans;
}
void printsolutions(int level,int left){
    // base case
    if(level==n+1) return;
    if(dp3(level+1,left)==1) printsolutions(level+1,left); // not take
    else if(dp3(level+1,left-x[level])==1){
        cout << x[level] << " ";
        printsolutions(level+1,left-x[level]); // take
    }
}

int a[1001];

//
int recursion(int i,int j){
    // pruning
    if(j<0) return INT_MAX;
    if(i+1<j) return INT_MAX;
    // base case
    if(i==0){
        if(j==0) return 0;
        else return INT_MAX;
    }
    // cache check

    //computation
    int max1=a[i];
    int ans=INT_MAX;
    for(int k=i;k>=0;k--){
        max1=max(max1,a[k]);
        ans=min(ans,max1+recursion(k-1,j-1));
    }
    return ans;
}