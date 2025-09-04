#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Hashing{
    string s;
    int n;
    int primes;
    vector<long long> hashprimes={100000009,100000007}; // i.e.%m
    vector<vector<long long>> hashvalues; // store prefix hashes -> precomputed
    vector<vector<long long>> powerofbases; // calculated the power of bases i.e. P base and its power of 0,1,2,3,4... -> precomputed
    vector<vector<long long>> inversepowerofbases; // inverse power-> the denominator term in substring hashing becomes inverse power and mod with m.
    Hashing(string a){
        int primes=size(hashprimes);
        hashvalues.resize(primes); // hashvalues is a 2d array (hashvalues[0] -> corresponding to m1,hashvalues[1]->corresponding to m2)
        powerofbases.resize(primes);
        powerofbases.resize(primes);
        s=a;
        n=s.length();
        for(int i=0;i<size(hashprimes);i++){
            powerofbases[i].resize(n+1);
            inversepowerofbases[i].resize(n+1);
            powerofbases[i][0]=1;
            inversepowerofbases[i][0];
        }
    }

};