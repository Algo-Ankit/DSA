#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int ans=0;

    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count=0,moves=0;
            while(n%i==0){
                count++;
                n/=i;
            }
            // this prime we got and its power is count-> so we can check for moves
            while((moves)*(moves+1)/2 <= count)moves++;
            ans +=(moves-1);
        }
    }
    cout<<ans+(n>1)<<"\n";
}
