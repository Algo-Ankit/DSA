#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<long long> v(n);
    
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    long long median = (n % 2 == 0) ? v[n/2 - 1] : v[n/2];  // Pick the actual element from the array

    long long ans = 0;
    for(int i = 0; i < n; i++) ans += abs(v[i] - median);  // Corrected absolute difference

    cout << ans << endl;
}
