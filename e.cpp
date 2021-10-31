#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int N = 30228;

int a[N], b[N];
int ac, bc;

int l[N];
int r[N];

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            a[ac++] = i;
        }

        if (t[i] != t[i - 1]) {
            b[bc++] = i;
        }
    }

    int ans = N * N;

    bool eq = s[0] == t[0];
    for (int i = -n - 1; i <= n + 1; ++i) {
        if ((i % 2 == 0) != eq) {
            continue;
        }

        int lc = 0, rc = 0;

        if (i > 0) {
            fill(l, l + i, 0);
            lc = i;
        } else {
            fill(r, r + (-i), 0);
            rc = -i;
        }

        copy(a, a + ac, l + lc);
        copy(b, b + bc, r + rc);
        lc += ac;
        rc += bc;
        while (lc < rc) {
            l[lc++] = n;
        }

        while (rc < lc) {
            r[rc++] = n;
        }

        int cur = 0;
        for (int j = 0; j < lc; ++j) {
            cur += abs(l[j] - r[j]);
        }

        ans = min(ans, cur);
    }

    cout << ans << "\n";
}

