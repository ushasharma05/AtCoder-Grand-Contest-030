#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int N = 328;
using Arr = array<array<ll, N>, N>;
const int MOD = int(1e9 + 7);

const int M = N * 2;

int a[M];
int ac;

int w[M];

void ad(ll& x, ll y) {
    x = (x + y) % MOD;
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n;
    cin >> n;

    int free = 0;

    int one = 0;

    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }

        if (x != -1 && y != -1) {
            w[x] = w[y] = 1;
        }

        if (x == -1 && y != -1) {
            ++a[y];
            w[y] = 2;
            ++one;
        }

        if (y == -1) {
            ++free;
        }

    }

    int m = 2 * n;

    for (int i = m; i > 0; --i) {
        a[i] += a[i + 1];
    }

    Arr f{};
    f[0][0] = 1;

    for (int i = 2 * n; i >= 1; --i) {
        if (w[i] == 1) {
            continue;
        }

        Arr g{};

        if (w[i] == 0) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= one; ++k) {
                    if (k) {
                        ad(g[j][k - 1], f[j][k] * k);
                    }

                    if (j) {
                        ad(g[j - 1][k], f[j][k]);   
                    }

                    ad(g[j + 1][k], f[j][k]);
                }
            }
        } else {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= one; ++k) {
                    if (j) {
                        ad(g[j - 1][k], f[j][k]);
                    }

                    ad(g[j][k + 1], f[j][k]);
                }
            }
        }

        f = g;
    }

    ll ans = f[0][0];
    for (int i = 1; i <= free; ++i) {
        ans = ans * i % MOD;
    }

    cout << ans << "\n";
}

