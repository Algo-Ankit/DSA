#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ans = 0;
        for(int i = 0; i < (k + 1) / 2; i++){
            vector<int> freq(26, 0);

            for(int j = 0; j < n; j += k){
                // Get character at position i in the block
                freq[s[j + i] - 'a']++;

                // If it's not a self-mirror (i != k - 1 - i), get the mirrored position
                if(i != k - 1 - i){
                    freq[s[j + (k - 1 - i)] - 'a']++;
                }
            }

            // Total characters in this group
            int total = (n / k) * (i == k - 1 - i ? 1 : 2);
            int max_freq = *max_element(freq.begin(), freq.end());

            ans += (total - max_freq);
        }

        cout << ans << '\n';
    }

    return 0;
}
