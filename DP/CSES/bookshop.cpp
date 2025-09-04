#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

vector<int> prices, pages;
vector<vector<int>> dp;
int n, x;

int rec(int level, int budget) {
    if (level == n) return 0; // base case

    if (dp[level][budget] != -1) return dp[level][budget];

    int ans = rec(level + 1, budget); // don't take
    if (budget >= prices[level])
        ans = max(ans, rec(level + 1, budget - prices[level]) + pages[level]); // take

    return dp[level][budget] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x;
    prices.resize(n);
    pages.resize(n);
    for (int &p : prices) cin >> p;
    for (int &p : pages) cin >> p;

    dp.assign(n + 1, vector<int>(x + 1, -1));

    cout << rec(0, x) << "\n";
}
