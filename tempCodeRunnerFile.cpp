#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        // Edge cases: k<2 or n-k<2 → zero 101/010 in any arrangement
        if (k < 2 || n - k < 2) {
            cout << string(k, '1') << string(n - k, '0') << "\n";
        }
        else {
            // a=1, b=(n-k)-1, c=k-1, d=1
            int b = (n - k) - 1;
            int c = k - 1;
            cout << '1'
                 << string(b, '0')
                 << string(c, '1')
                 << '0'
                 << "\n";
        }
    }
    return 0;
}
