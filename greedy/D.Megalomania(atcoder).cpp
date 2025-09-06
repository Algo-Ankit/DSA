#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;

    sort(v.begin(), v.end());

    int start = 0;
    for (auto &it : v) {
        if (it.first < it.second + start) {
            cout << "No";
            return 0;
        } else {
            start += it.second;
        }
    }

    cout << "Yes";
}
