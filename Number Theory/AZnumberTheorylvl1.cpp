#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6 + 1;
vector<bool> is_prime(MAX, true);


// Templates and Methods

// Binary exponentiation: a^b
long long binaryExpo(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1)  // If b is odd
            result *= a;
        a *= a;
        b >>= 1;    // Divide b by 2
    }
    return result;
}
//Prime factorization using trial division
vector<ll> primeFactorize(ll n) {
    vector<ll> factors;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}// root(n) complexity -> naive approach
// Sieve of Eratosthenes
void sieve() {
    is_prime[0] = false;  // 0 is NOT prime
    is_prime[1] = false;  // 1 is NOT prime

    for (int i = 2; i * i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
// Naive prime check -> root(n) complexity
bool isPrimeNaive(long long n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    for (long long i = 2; i * i <= n; ++i) { // Only check up to sqrt(n)
        if (n % i == 0) return false; // Found a divisor => not prime
    }
    return true; // No divisors => prime
}


//Questions
// CF TPrimes 1300
void Tprimes(){
    int n; cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sieve();
    for(int i=0;i<n;i++){
        long long root=(long long)sqrt(a[i]);
        if(is_prime[root]==1 && root*root==a[i]) cout<<"YES\n";
        else cout<<"NO\n"; 
    }
}
// CF Design Tutorial: Learn from Math 800
void DesignTutorialLearnformMath(){
    int n; cin>>n;
    sieve();
    for(int i=4;i<=n;i++){ 
        if(is_prime[i]==0 && is_prime[n-i]==0){
            cout<<i<<" "<<n-i<<"\n";
            return;
        }
    }
    
}
// CF Dima And Lisa 1800
/*
void DimaandLisa(){
    long long n;cin>>n;
    sieve();
    if(is_prime[n]==1){
        cout<<1<<"\n";
        cout<<n<<"\n";
    } 
    else if(is_prime[n-2]==1){
        cout<<2<<"\n";
        cout<<2<<" "<<n-2<<"\n";
    
    }
    else{
        long long x=n-3;
        for(int i=4;i<=n;i++){ // goldbachs conjecture
            if(is_prime[i]==1 && is_prime[x-i]==1){
                cout<<3<<"\n";
                cout<<3<<" "<<i<<" "<<x-i<<"\n";
                return;
            }
        }
    }  
}-> not optimal for 1e6 , cannot be used for n<=1e9
-> oNE WAY IS TO USE JUST MILLER RABIN TEST AS IT IS VALID TILL 1e18
->OR UDING THE WAY OF NAIVE CHECK IN ROOT(N) TIME
*/
void DimaandLisa(){
    long long n; cin>>n;
    if(isPrimeNaive(n)){
        cout<<1<<"\n";
        cout<<n<<"\n";
    }
    else{
        cout<<3<<endl<<3<<" ";  
        n-=3;
        for(long long i=3;i<n;i+=2 /* ->this checks only odd numbers*/){
            if(isPrimeNaive(i)&&isPrimeNaive(n-i)){
                cout<<i<<" "<<n-i<<endl;
                return;
            }
        }
    }
}
// CF k-Factorization 1100
void kFactorization(){
    int n,k; cin>>n>>k;
    vector<ll> factors=primeFactorize(n);
    if((int)factors.size()<k){
        cout<<-1<<"\n";
        return;
    }
    // Merge the last factors until size is k
    while ((int)factors.size() > k) {
        ll back1 = factors.back(); factors.pop_back();
        ll back2 = factors.back(); factors.pop_back();
        factors.push_back(back1 * back2);
    }
    for (ll f : factors) cout << f << " ";
    cout << "\n";
}
// CF-Vatsya and petyas Game 1500
void vatsyaandpetya(){
    int n;cin>>n;
    sieve();
    vector<int> res;
    for(int i=0;i<n;i++){
        if(is_prime[i]){
            ll p=i;
            while(p<=n){
                res.push_back(p);
                p*=i;
            }
        }
    }
    cout<<res.size()<<"\n";
    for(int result:res) cout<<result<<" ";
}
// CF-Arpas Hard exam and Mehrdad's naive cheat 1000
void arpasexam(){
    long long n;
    cin >> n;

    if (n == 0)
        cout << 1 << "\n";  // 1378^0 = 1
    else {
        int cycle[] = {8, 4, 2, 6};  // cycle of last digits of 8^n
        cout << cycle[(n - 1) % 4] << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vatsyaandpetya();
    return 0;
}