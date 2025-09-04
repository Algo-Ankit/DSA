#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 1;
// CSES Problem Set -> Common Divisor(MAthematics)
void CommonDivisor(){
    int n;
    cin>>n;
    vector<int> f(MAX, 0);  // frequency array

    // we juct have to find a number such that it has >= 2 occurences
    // and it is the maximum number -> solved using the sieve of eratosthenes
    // how many numbers are div by x = (summation of (f[x]+f[2x]+f[3x]+...+f[n/x]))
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        f[x]++;
    }
    for(int i=MAX-1;i>=1;i--){
        int count=0;
        for(int j=i;j<=MAX-1;j+=i){
            count+=f[j];
            if(count>=2) break;  // we just need to check if count >= 2
        }
        if(count>=2){
            cout<<i<<"\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    CommonDivisor();
    return 0;
}