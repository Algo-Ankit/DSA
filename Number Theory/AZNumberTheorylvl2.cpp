#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Templates and functions
//1.Euler Totient function
int phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            // If p divides n, then remove all multiples of p from n
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    // If n is still > 1, it means n is a prime factor
    if (n > 1)
        result -= result / n;
    return result;
}
//2. Function to calculate GCD using Euclidean algorithm
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}



//Questions
// Q2-> Playing with paper 1100
void playingwithpaper()
{
    ll a, b;
    cin >> a >> b;
    ll answer = 0;
    while (b != 0)
    {
        answer += a / b;
        ll temp = a % b;
        a = b;
        b = temp;
        //a, b = b, a % b; Euclidean algorithm -> to find GCD
    }
    cout << answer << endl;
}
//Q3 ->Rational Resistance 1600
void rationalresistance(){
    ll a,b; cin>>a>>b;
    int count=0;
    while(a!=0 && b!=0){
        if(a>b) {
            count+=a/b;
            a%=b;
        }
        if(b>a) {
            count+=b/a;
            b%=a;
        }
    }
    cout<<count<<endl;
}
// Q4-> oleg and shares 900
void olegandshares(){
    int n,k;cin>>n>>k;
    vector<int> shares(n);
    for(int i=0;i<n;i++) cin>>shares[i];

    sort(shares.begin(), shares.end());
    int count = 0;
    int min= shares[0];
    for(int i=1;i<n;i++){
        if((shares[i]-min)%k==0){
            count+=(shares[i]-min)/k;
        }
        else {
            cout<<-1<<endl; 
            return;
        }
    }
    cout<<count<<endl;
}
//Q5-> Cows and Primitive roots 1400
void cowsandprimitiveroots(){
    int n;cin>>n;
    cout<<phi(n-1)<<endl;
    // the number of primitive roots modulo n is equal to the Euler's totient function of n-1
}
//ATCODER
//Q6-> GCD on Blackboard (C)
void GCDonBlackboard(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    // Precomputation
    vector<int> prefixgcd(n),suffixgcd(n);
    prefixgcd[0]= a[0];
    for(int i=1;i<n;i++){
        prefixgcd[i]=gcd(prefixgcd[i-1],a[i]);
    }
    suffixgcd[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suffixgcd[i]=gcd(suffixgcd[i+1], a[i]);
    }
    
    int maxGCD=0;
    int currgcd;
    for(int i=0;i<n;i++){
        if(i==0) currgcd=suffixgcd[1];
        if(i==n-1) currgcd=prefixgcd[n-2];
        else currgcd=gcd(prefixgcd[i-1],suffixgcd[i+1]);
        maxGCD=max(maxGCD,currgcd);
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    playingwithpaper();
}