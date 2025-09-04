#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU
{
public:
    vector<int> rank, parent, size;
    vector<int> componentMin; // componentMin[root] = minimum element in that component
    vector<int> componentMax; // componentMax[root] = maximum element in that component
    
    vector<int> exp;    // lazy experience for component (only for root)
    vector<int> delta;  // difference for each node
    // delta[u] = exp[pu] - exp[u] where pu is the parent of u

    DSU(int n)
    {
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
       delta.resize(n, 0); 
        exp.resize(n, 0); // Initialize experience to 0 for each component
        componentMin.resize(n);
        componentMax.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            componentMin[i] = i; // Initialize min to itself
            componentMax[i] = i; // Initialize max to itself
        }
    }
    int findParent(int u)
    {
        if (u == parent[u]) return u;
        int par = findParent(parent[u]);
        delta[u] += delta[parent[u]]; // accumulate delta along the path
        return parent[u] = par;
    }
    void unionbySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu == pv)
            return; // u and V are already in same component
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
            delta[pu] = exp[pv] - exp[pu];
            componentMin[pv] = min(componentMin[pu], componentMin[pv]);
            componentMax[pv] = max(componentMax[pu], componentMax[pv]);
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
            delta[pv] = exp[pu] - exp[pv];
            componentMin[pu] = min(componentMin[pu], componentMin[pv]);
            componentMax[pu] = max(componentMax[pu], componentMax[pv]);
        }
    }
    // get minimum element in u’s component
    int getMin(int u)
    {
        return componentMin[findParent(u)];
    }

    // get maximum element in u’s component
    int getMax(int u)
    {
        return componentMax[findParent(u)];
    }
    int getSize(int u)
    {
        return size[findParent(u)];
    }

    int addexp(int V ,int u)
    {
        int pu = findParent(u);
        exp[pu]+= V;
    }
    int getexp(int u){
        findParent(u);
        return exp[parent[u]]- delta[u];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--)
    {
        string c;
        cin >> c;
        if (c == "join")
        {
            int u, v;
            cin >> u >> v;
            dsu.unionbySize(u, v);
        }
        else if (c == "add")
        {
            int x, v;
            cin >> x >> v;
            dsu.addexp(v, x);
        }
        else
        {
            int x;cin >> x;
            cout<< dsu.getexp(x)<<"\n"; // Output the total experience of the component
        }
    }
}