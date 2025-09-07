#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) ((int)(x).size())

// ------------------ Modular helper functions ------------------

// Fast modular exponentiation: (a^e) % mod
ll mod_pow(ll a, ll e, ll mod) {
    ll res = 1 % mod;
    a %= mod;
    if (a < 0) a += mod;
    while (e > 0) {
        if (e & 1) res = ( (__int128)res * a ) % mod;
        a = ( (__int128)a * a ) % mod;
        e >>= 1;
    }
    return res;
}

// Modular inverse when mod is prime: a^(mod-2) % mod
ll mminvprime(ll a, ll mod) {
    a %= mod;
    if (a < 0) a += mod;
    return mod_pow(a, mod - 2, mod);
}
// alias in case you used a different name
inline ll minvprime(ll a, ll mod) { return mminvprime(a, mod); }

// Safe modular multiplication using __int128 to avoid overflow
inline ll mod_mul(ll a, ll b, ll mod) {
    a %= mod; if (a < 0) a += mod;
    b %= mod; if (b < 0) b += mod;
    return ( (__int128)a * b ) % mod;
}

// Modular addition / subtraction (results in [0, mod-1])
inline ll mod_add(ll a, ll b, ll mod) {
    a %= mod; b %= mod;
    ll res = a + b;
    if (res >= mod) res -= mod;
    return res;
}
inline ll mod_sub(ll a, ll b, ll mod) {
    a %= mod; b %= mod;
    ll res = a - b;
    if (res < 0) res += mod;
    return res;
}

struct StringHash {
    string text;                         // input string
    int n;                               // length of string
    int numMods;                         // number of prime moduli
    vector<ll> modList = {1000000009, 100000007};  // mod values (double hashing)
    const ll hashBase = 31;              // base for polynomial hashing

    // Precomputed values
    vector<vector<ll>> prefixHashes;     // prefixHashes[i][j] = hash of prefix [0..j] under modList[i]
    vector<vector<ll>> basePowers;       // basePowers[i][j] = (base^j) % modList[i]
    vector<vector<ll>> invBasePowers;    // invBasePowers[i][j] = modular inverse of base^j under modList[i]

    StringHash(string s) {
        text = s;
        n = text.length();
        numMods = sz(modList);

        prefixHashes.resize(numMods);
        basePowers.resize(numMods);
        invBasePowers.resize(numMods);

        // Precompute base powers and their modular inverses
        for (int i = 0; i < numMods; i++) {
            basePowers[i].resize(n + 1);
            invBasePowers[i].resize(n + 1);

            basePowers[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                basePowers[i][j] = (hashBase * basePowers[i][j - 1]) % modList[i];
            }

            // modular inverse for base^n
            invBasePowers[i][n] = mminvprime(basePowers[i][n], modList[i]);
            for (int j = n - 1; j >= 0; j--) {
                invBasePowers[i][j] = mod_mul(invBasePowers[i][j + 1], hashBase, modList[i]);
            }
        }

        // Compute prefix hashes
        for (int i = 0; i < numMods; i++) {
            prefixHashes[i].resize(n);
            for (int j = 0; j < n; j++) {
                prefixHashes[i][j] = ((text[j] - 'a' + 1LL) * basePowers[i][j]) % modList[i];
                prefixHashes[i][j] = (prefixHashes[i][j] + (j > 0 ? prefixHashes[i][j - 1] : 0LL)) % modList[i];
            }
        }
    }

    // Get hash of substring text[l..r] inclusive
    vector<ll> getSubstringHash(int l, int r) {
        vector<ll> hash(numMods);
        for (int i = 0; i < numMods; i++) {
            ll totalHash = prefixHashes[i][r];
            ll beforeHash = (l > 0 ? prefixHashes[i][l - 1] : 0LL);
            hash[i] = mod_mul(mod_sub(totalHash, beforeHash, modList[i]),
                              invBasePowers[i][l], modList[i]);
        }
        return hash;
    }
};
