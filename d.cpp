#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int N = 3002;
const int MOD = int(1e9 + 7);
const ll R2 = (MOD + 1) / 2;

ll f[N][N];
int a[N];
int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = a[i] < a[j];
        }
    }

    ll mul = 1;

    for (int i = 0; i < q; ++i) {
        mul = (mul * 2) % MOD;
        int x, y;
        cin >> x >> y;

        for (int j = 1; j <= n; ++j) {
            if (j != x && j != y) {
                f[j][x] = f[j][y] = (f[j][x] + f[j][y]) * R2 % MOD;
                f[x][j] = f[y][j] = (f[x][j] + f[y][j]) * R2 % MOD;
            }
        }

        f[x][y] = f[y][x] = (f[x][y] + f[y][x]) * R2 % MOD;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            ans += f[i][j];
        }
    }

    ans %= MOD;

    cout << (ans * mul) % MOD << "\n";
}

