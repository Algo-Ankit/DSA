#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // This code portion does i/o file handling
	#ifndef ONLINE_JUDGE
	// for getting input
	freopen("input.txt","r",stdin);
	// for writing output 
	freopen("output.txt","w+",stdout);
	#endif
 
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> hoplength(n);
        for (int i = 0; i < n; i++) {
            cin >> hoplength[i];
        }
 
        vector<int> freq(n + 1, 0);  // Only store frequencies for values <= n
        for (int i = 0; i < n; i++) {
            if (hoplength[i] <= n) {
                freq[hoplength[i]]++;
            }
        }
 
        vector<int> trappedfrogs(n + 1, 0);  // Ensure size is `n+1` only
 
        for (int h = 1; h <= n; h++) {  
            if (freq[h] > 0) {  
                for (int i = h; i <= n; i += h) {  
                    trappedfrogs[i] += freq[h];
                }
            }
        }
 
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, trappedfrogs[i]);
        }
 
        cout << ans << endl;
    }
 
    return 0;
}
