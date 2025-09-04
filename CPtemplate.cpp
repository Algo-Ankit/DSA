#include <bits/stdc++.h>
using namespace std;
// Common headers to remember: <iostream>, <vector>, <algorithm>, <string>, and <cmath>.

const int MOD = 1e9 + 7; // Common MOD value
const int MAXN = 1e6 + 5; // Maximum n value for precomputation

long long fact[MAXN], ifact[MAXN]; // Factorial and Inverse Factorial arrays
long long power(long long x, long long y, long long mod) {
    long long res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;} // Fast modular exponentiation: (x^y) % MOD
void precomputeFactorials() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ifact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2, MOD); // Using Fermat’s Theorem
    for (int i = MAXN - 2; i >= 1; i--) {
        ifact[i] = (ifact[i + 1] * (i + 1)) % MOD;
    }} // Precompute factorials and inverse factorials->O(N)
long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return (fact[n] * ifact[r] % MOD * ifact[n - r] % MOD) % MOD;} // Compute nCr using precomputed values in O(1) time
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);} // Function to calculate the GCD
int lcm(int a, int b) {
    return a * b / gcd(a, b);} // Function to calculate LCM
vector<int> primeFactorization(int n) {
    vector<int> factors;
    // Divide by 2 until n is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    // Check odd numbers from 3 onwards
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    // If n is prime and greater than 2
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;} // Finds the prime factors via trial division -> O(sqrt(n))
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;} // checks prime-> trial division
int binaryExponentiation(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) {  // If the exponent is odd, multiply by a
            result *= a;
        }
        a = a * a;  // Square the base
        b /= 2;  // Halve the exponent
    }
    return result;} // Binary expopnentiation
int modularExponentiation(int a, int b, int m) {
    int result = 1;
    a = a % m;  // Handle the case when a is larger than m
    while (b > 0) {
        if (b % 2 == 1) {  // If the exponent is odd, multiply by a
            result = (result * a) % m;
        }
        a = (a * a) % m;  // Square the base and take mod m
        b /= 2;  // Halve the exponent
    }
    return result;} // Modular Exponentiation -> binary exp but uses mod to operate on bigger values
int extendedGCD(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int g = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return g;} // Extended Euclidean Algorithm to find gcd and coefficients x, y such that ax + by = gcd(a, b)

int main(){
	// This code portion does i/o file handling
	#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input.txt","r",stdin);
	// for writing output 
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	while(t-->0){
        //Answer is the maxm count of frogs getting trapped at X,where X is in[1 to N]
        // And if hoplength > N -> then it cant be captured
		int n;
		cin>>n;
        vector<int> hoplength(n);
		for (int i=0;i<n;i++) cin>>hoplength[i];
        vector<int> freq(200001,0); // initialized with 0's
        for (int i = 0; i < n; i++) freq[hoplength[i]]++;
        vector<int> trappedfrogs(n+1,0); // this represents the count of frogs for each trap coordinate i

        for (int h = 1; h <= n ; h++){ 
            for (int i=h;i<=n;i+=h){
                trappedfrogs[i] += freq[h];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,trappedfrogs[i]);
        }
        cout<<ans<<endl;

		
	}

}