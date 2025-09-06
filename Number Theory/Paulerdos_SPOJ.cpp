#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e7+5;
int isPrime[N],isType[N],prefix[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Sieve of Eratosthenes
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<N;i++)
    {
        if(isPrime[i]) for(int j=i*i;j<N;j+=i) isPrime[j]=0;            
    }

    //Checking the second condition
    for(int i=0;i*i<N;i++){
        for(int j=0;j*j*j*j<N;j++){
            isType[i*i + j*j*j*j] = 1;     
        }
    }

    //Prefix sum array-> checking both conditions array and storing 1 in the index 
    for(int i=1;i<N;i++)
        prefix[i] = (isPrime[i] && isType[i]) ? 1 : 0;
    //Adding the 1's counted satisfying both conditions
    for(int i=0;i<N;i++)
        prefix[i] += prefix[i-1];

    int t;cin>>t; // Test Cases
    while(t--)
    {
        int x;cin>>x;
        cout<<prefix[x]<<"\n";
    }

} 
