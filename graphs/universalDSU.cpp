#include <bits/stdc++.h>
using namespace std;

/*------------------------------------------------------------
  1) STATIC DSU: path compression + union by size
------------------------------------------------------------*/
struct DisjointSet {
    vector<int> parent, compSize;

    DisjointSet(int n) {
        parent.resize(n+1);
        compSize.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findRoot(int u) {
        return parent[u] == u
            ? u
            : parent[u] = findRoot(parent[u]);
    }

    bool uniteBySize(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v) return false;
        if (compSize[u] < compSize[v]) swap(u, v);
        parent[v] = u;
        compSize[u] += compSize[v];
        return true;
    }

    bool connected(int u, int v) {
        return findRoot(u) == findRoot(v);
    }

    int sizeOfComponent(int u) {
        return compSize[findRoot(u)];
    }
};


/*------------------------------------------------------------
  2) ROLLBACK DSU: supports undo()
------------------------------------------------------------*/
struct RollbackDSU {
    vector<int> parent, compSize;
    // stack of changes: (v, old_parent_v), (u, old_size_u)
    vector<pair<int,int>> history;

    RollbackDSU(int n) {
        parent.resize(n+1);
        compSize.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findRoot(int u) {
        while (parent[u] != u) u = parent[u];
        return u;
    }

    bool unite(int u, int v) {
        u = findRoot(u); 
        v = findRoot(v);
        if (u == v) return false;
        // make u the bigger
        if (compSize[u] < compSize[v]) swap(u, v);
        // record history
        history.emplace_back(v, parent[v]);
        history.emplace_back(u, compSize[u]);
        // apply union
        parent[v] = u;
        compSize[u] += compSize[v];
        return true;
    }

    void undo() {
        // revert last two changes
        if (history.empty()) return;
        auto [u, oldSize] = history.back(); history.pop_back();
        auto [v, oldParent] = history.back(); history.pop_back();
        compSize[u] = oldSize;
        parent[v] = oldParent;
    }

    int snapshot() {
        return history.size();
    }

    void revertToSnapshot(int snap) {
        while ((int)history.size() > snap) undo();
    }
};


/*------------------------------------------------------------
  3) OFFLINE DYNAMIC CONNECTIVITY
     (divide-and-conquer on time with segment tree)
------------------------------------------------------------*/
struct DynamicConnectivity {
    struct Edge { int u, v; };
    int n, Q;
    vector<vector<Edge>> segtree;
    RollbackDSU dsu;

    DynamicConnectivity(int nodes, int queries)
      : n(nodes), Q(queries), dsu(nodes)
    {
        segtree.assign(4*(Q+1), {});
    }

    // add edge to be active on interval [l, r)
    void addEdge(int idx, int l, int r, int ql, int qr, Edge e){
        if (ql >= r || qr <= l) return;
        if (ql <= l && r <= qr) {
            segtree[idx].push_back(e);
            return;
        }
        int m = (l + r) >> 1;
        addEdge(2*idx, l, m, ql, qr, e);
        addEdge(2*idx+1, m, r, ql, qr, e);
    }

    // to be called once per query type 2 (deletion), pair up with insertion times
    void scheduleEdge(int timeInsert, int timeDelete, int u, int v) {
        // active in [timeInsert, timeDelete)
        addEdge(1, 0, Q, timeInsert, timeDelete, {u, v});
    }

    // override this to answer at leaves
    virtual void onQuery(int time) = 0;

    void dfs(int idx, int l, int r) {
        int snap = dsu.snapshot();
        for (auto &e : segtree[idx]) {
            dsu.unite(e.u, e.v);
        }
        if (l + 1 == r) {
            onQuery(l);
        } else {
            int m = (l + r) >> 1;
            dfs(2*idx, l, m);
            dfs(2*idx+1, m, r);
        }
        dsu.revertToSnapshot(snap);
    }

    void solve() {
        dfs(1, 0, Q);
    }
};


/*------------------------------------------------------------
  4) PARITY DSU: track bipartiteness or XOR distances
------------------------------------------------------------*/
struct ParityDSU {
    vector<int> parent, parity, compSize;

    ParityDSU(int n) {
        parent.resize(n+1);
        parity.assign(n+1, 0);
        compSize.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    // find root and compute parity[u] = xor-distance to root
    int findRoot(int u) {
        if (parent[u] == u) return u;
        int p = parent[u];
        parent[u] = findRoot(p);
        parity[u] ^= parity[p];
        return parent[u];
    }

    // unite u,v with requirement that parity[u] ^ parity[v] == w (0 or 1)
    // returns false if contradiction detected
    bool unite(int u, int v, int w) {
        int ru = findRoot(u), rv = findRoot(v);
        if (ru == rv) {
            // check consistency
            return ((parity[u] ^ parity[v]) == w);
        }
        // union by size
        if (compSize[ru] < compSize[rv]) {
            swap(u, v);
            swap(ru, rv);
        }
        // attach rv under ru
        parent[rv] = ru;
        // set parity[rv] so that parity[u] ^ parity[v] == w
        parity[rv] = parity[u] ^ parity[v] ^ w;
        compSize[ru] += compSize[rv];
        return true;
    }

    // check if u,v are in same component and parity condition holds
    bool isSameComponent(int u, int v) {
        return findRoot(u) == findRoot(v);
    }

    // get xor-distance between u and v (only valid if connected)
    int getXorDistance(int u, int v) {
        findRoot(u); findRoot(v);
        return parity[u] ^ parity[v];
    }
};




// To move element U to the component with element v
#include <bits/stdc++.h>
using namespace std;

/*
  DSU with Move:
  - n = initial number of elements (1‑based)
  - maxOps = upper bound on total number of move() calls
    (we'll allocate up to n + maxOps node‑IDs)

  Amortized O(alpha(N)) per op.
*/
struct DSUWithMove {
    int nextFreeID;
    vector<int> parent;          // parent[x] = DSU parent of node‑ID x
    vector<int> compSize;        // compSize[find(x)] = size of that component
    vector<int> head;            // head[find(x)] = first node‑ID in its list
    vector<int> nxt, prv;        // doubly‑linked list of node‑IDs
    vector<int> currentID;       // currentID[u] = the node‑ID that currently represents element u

    DSUWithMove(int n, int maxMoves)
      : nextFreeID(n),
        parent(n + maxMoves + 5),
        compSize(n + maxMoves + 5),
        head(n + maxMoves + 5, 0),
        nxt(n + maxMoves + 5, 0),
        prv(n + maxMoves + 5, 0),
        currentID(n + 1)
    {
        // initialize IDs 1..n
        for (int u = 1; u <= n; u++) {
            currentID[u] = u;
            parent[u]    = u;
            compSize[u]  = 1;
            head[u]      = u;
            // list of length 1: head=u, nxt/prv=0
            nxt[u] = prv[u] = 0;
        }
    }

    // classic find with path‑compression
    int findRoot(int x) {
        return parent[x] == x
             ? x
             : parent[x] = findRoot(parent[x]);
    }

    // union‑by‑size
    bool merge(int u, int v) {
        int ru = findRoot(currentID[u]);
        int rv = findRoot(currentID[v]);
        if (ru == rv) return false;
        // make ru the larger
        if (compSize[ru] < compSize[rv]) swap(ru, rv);
        // attach rv → ru
        parent[rv] = ru;
        compSize[ru] += compSize[rv];

        // splice the linked list of rv onto ru’s list:
        //   head[ru] is some node in ru; we'll insert rv’s chain before it
        int hru = head[ru];
        int hrv = head[rv];

        // find tail of rv’s list
        int tailRv = hrv;
        while (nxt[tailRv]) tailRv = nxt[tailRv];

        // splice [hrv…tailRv] before hru
        prv[hru]       = tailRv;
        nxt[tailRv]    = hru;
        head[ru]       = hrv;    // new head
        head[rv]       = 0;      // invalidated

        return true;
    }

    // move element u → component of v
    void move(int u, int v) {
        int oldID = currentID[u];
        int ru    = findRoot(oldID);
        int rv    = findRoot(currentID[v]);
        if (ru == rv) return;  // already together

        // 1) unlink oldID from ru’s list
        int p = prv[oldID], n = nxt[oldID];
        if (p) nxt[p] = n;
        if (n) prv[n] = p;
        if (head[ru] == oldID) head[ru] = n; 
        compSize[ru]--;

        // 2) allocate a brand‑new node‑ID
        int nid = ++nextFreeID;
        currentID[u] = nid;
        parent[nid]   = nid;
        compSize[nid] = 1;
        head[nid]     = nid;
        nxt[nid] = prv[nid] = 0;

        // 3) merge that singleton into rv
        int rootV = findRoot(currentID[v]);
        parent[nid] = rootV;
        compSize[rootV]++;

        // splice nid into rv’s list before head[rootV]
        int h = head[rootV];
        prv[h]    = nid;
        nxt[nid]  = h;
        head[rootV] = nid;
    }

    // are u,v in the same component?
    bool connected(int u, int v) {
        return findRoot(currentID[u]) == findRoot(currentID[v]);
    }

    // size of u’s component
    int sizeOf(int u) {
        return compSize[findRoot(currentID[u])];
    }
};
