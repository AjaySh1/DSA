#define ll long long
#define MOD 1000000007

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2)
            res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

ll mod_inv(ll a) {
    return power(a, MOD - 2); // Fermat's little theorem
}

class Solution {
public:
    vector<ll> fact, inv_fact;

    void precompute(int n) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        inv_fact[n] = mod_inv(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }
    }

    ll nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precompute(n);
        ll comb = nCr(n - 1, k);
        ll pow_term = power(m - 1, n - 1 - k);
        return comb * m % MOD * pow_term % MOD;
    }
};
