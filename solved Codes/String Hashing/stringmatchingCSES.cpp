#include <bits/stdc++.h>
using namespace std; 

long long mod_mul(long long a, long long b, long long m) {return ((a % m) * (b % m)) % m;}
long long mod_sub(long long a, long long b, long long m) {return ((a % m) - (b % m) + m) % m;}
long long binexp(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;}
long long mminvprime(long long a, long long m) {return binexp(a, m - 2, m);} // m must be prime


struct Hashing{
    string s;
    int n;
    int primes;
    vector<long long> hashprimes={100000009,100000007};
    const long long base=31;
    vector<vector<long long>> hashvalues; //prefix hashes
    vector<vector<long long>> powerofbases;
    vector<vector<long long>> inversepowerofbases; 
    Hashing(string a){
        primes=hashprimes.size();
        hashvalues.resize(primes);
        powerofbases.resize(primes);
        inversepowerofbases.resize(primes);
        s=a;
        n=s.length();
        for (int i = 0; i < hashprimes.size(); i++)
        {
            powerofbases[i].resize(n+1);
            inversepowerofbases[i].resize(n+1);
            powerofbases[i][0]=1;
            for (int j =1 ; j<=n ; j++) powerofbases[i][j]=(base*powerofbases[i][j-1])%hashprimes[i];

            // 
            inversepowerofbases[i][0] = 1;
            long long invBase = mminvprime(base, hashprimes[i]);
            for (int j = 1; j <= n; j++) {
                inversepowerofbases[i][j] = (inversepowerofbases[i][j - 1] * invBase) % hashprimes[i];
            }

            //
        }
        for(int i=0;i<hashprimes.size();i++){
            hashvalues[i].resize(n);
            for(int j=0;j<n;j++){
                hashvalues[i][j]=((s[j]-'a'+1LL)*powerofbases[i][j])%hashprimes[i];
                hashvalues[i][j]=(hashvalues[i][j]+(j>0 ? hashvalues[i][j-1]:0LL))%hashprimes[i];
            }
        }
    }
    vector<long long> substringHash(int l,int r){
        vector<long long> hash(primes);
        for(int i=0;i<primes;i++){
            long long val1=hashvalues[i][r];
            long long val2=(l>0 ? hashvalues[i][l-1]: 0LL);
            hash[i]=mod_mul(mod_sub(val1,val2,hashprimes[i]),inversepowerofbases[i][l],hashprimes[i]);
        }
        return hash;
    } 
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    string str,pattern;
    cin>>str>>pattern;
    
    Hashing hash1(str);
    Hashing hash2(pattern);

    vector<long long> hashvalofPattern=hash2.substringHash(0,pattern.length()-1);
    long long numberOFmatches=0;
    int m = pattern.length(), n = str.length();
    for (int i = 0; i + m - 1 < n; i++) {
        if (hashvalofPattern == hash1.substringHash(i, i + m - 1)) numberOFmatches++;
    }
    cout<<numberOFmatches<<endl;
}
