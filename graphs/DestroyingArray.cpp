#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU
{
public:
    vector<int> parent, size;
    vector<ll>  sum;

    DSU(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        sum.resize(n + 1, 0LL);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    void makeSet(int x, int value)
    {
        parent[x] = x;
        size[x]   = 1;
        sum[x]    = (ll)value;
    }

    void unionSet(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv]  += size[pu];
            sum[pv]   += sum[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu]  += size[pv];
            sum[pu]   += sum[pv];
        }
    }

    ll sumOfSet(int x)
    {
        return sum[findParent(x)];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<int> a(n + 1, 0), state(n + 1, 0), seq(n);
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> seq[i];

    DSU dsu(n);
    vector<ll> ans(n);
    ll current_ans = 0;

    // Restore in reverse order, recording max‐segment sums
    for (int i = n - 1; i >= 0; --i)
    {
        int it = seq[i];
        state[it] = 1;
        dsu.makeSet(it, a[it]);

        if (it > 1 && state[it - 1])
            dsu.unionSet(it, it - 1);
        if (it < n && state[it + 1])
            dsu.unionSet(it, it + 1);

        current_ans = max(current_ans, dsu.sumOfSet(it));
        ans[i] = current_ans;
    }

    // Output answers after each destruction:
    // after destroying seq[0] → ans[1], …, after destroying seq[n-2] → ans[n-1], 
    // after destroying seq[n-1] → 0
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
            cout << ans[i + 1] << "\n";
        else
            cout << 0 << "\n";
    }

    return 0;
}
