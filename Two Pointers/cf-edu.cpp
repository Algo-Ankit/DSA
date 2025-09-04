#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

void numberOfEqual() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    long long pairs = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            int cnta = 1, cntb = 1;
            while (i+1 < n && a[i] == a[i+1]) {
                cnta++;
                i++;
            }
            while (j+1 < m && b[j] == b[j+1]) {
                cntb++;
                j++;
            }
            pairs += 1LL * cnta * cntb;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    cout << pairs << "\n";
}


void SegmentswithSmallset() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> freq;  
    int l = 0, r = 0;
    ll ans = 0;

    while (r < n) {
        freq[a[r]]++;

        while ((int)freq.size() > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) freq.erase(a[l]);
            l++;
        }

        ans += (r - l + 1); 
        r++;
    }
    cout << ans;
}
int main(){
    fast;

    numberOfEqual();
    return 0;
}