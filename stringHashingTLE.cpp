#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define sz(x) ((int)(x).size())
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


struct Hashing{
    string s;
    int n;
    int primes;
    vector<int> hashprimes = {1000000009, 100000007}; // double hashing
    const ll base = 31; // base for polynomial hashing

    vector<vector<int>> hashvalues;
    vector<vector<int>> powerBase;
    vector<vector<int>> invPowerBase;

    Hashing(string a){
        primes=sz(hashprimes);
        hashvalues.resize(primes); // hashvalues is a 2D array. first dim is number of primes, second dim is length of string
        // same thing to do with powers of base and inverse powers of base
        powerBase.resize(primes);
        invPowerBase.resize(primes); // 1st dim ios primes and 2nd dim is length of string
        s=a;
        n=sz(s);

        for(int i=0;i<primes;i++){
            powerBase[i].resize(n+1);
            invPowerBase[i].resize(n+1);
            hashvalues[i].resize(n+1);

            powerBase[i][0]=1; // base^0=1
            for(int j=0;j<n;j++){
                powerBase[i][j+1]=(base*powerBase[i][j])%hashprimes[i];
            }
            
        }

    }

};

