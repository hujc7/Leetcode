#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {

    int m, n;
    vector<vector<ll>> C(m+1, vector<ll>(n+1));
    for (int i = 0; i <= m; ++i) {
        C[i][0] = 1;
        for (int j = 0; j <= min(i, n); ++j) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return 0;
}