#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;


// ax == 1 (mod m) -> a = inv(x)

// x / a == x * b (mod m)
// a = inv(b)
ll quickPow(int x, int y) {
    ll res = 1, cur = x;
    while (y) {
        if (y & 1) res = res * cur % mod;
        cur = cur * cur % mod;
        y >>= 1;
    }

    return res;
}

ll inv(int x) {
    return quickPow(x, mod-2);
}