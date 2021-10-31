#include <bits/stdc++.h>
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

const int N = 400228;
ll a[N];
ll s[N];

ll ans = 0;

void gbest(int lg, int len, int rg, ll pos) {
    int lp = lg + len;
    int rp = rg - len;

    ll sl = 0, sr = 0;
    ll dr = a[rg - 1] - pos;
    ll dl = pos - a[lg];

    if (dr > dl) {
        sl += dl;
    } else {
        sr -= dr;
    }

    ll cl = s[lp] - s[lg];
    ll cr = s[rg] - s[rp];
    sl += cl * 2;
    sr += cr * 2;

    ans = max(ans, sr - sl);
}

ll eval(int lg, int rg, ll pos) {
    int md = lower_bound(a + lg, a + rg, pos) - a;

    if (md == lg) {
        return a[rg - 1] - pos;
    }

    if (md == rg) {
        return pos - a[lg];
    }

    int lp = md, rp = md;
    ll sl = 0, sr = 0;

    gbest(lg, min(md - lg, rg - md), rg, pos);

    if (md - lg == rg - md) {
        return 0;
    }
    
    if (md - lg > rg - md) {
        lp = lg + (rg - md) + 1;
        sr += pos;
        sl -= a[lg];
    } else {
        rp = rg - (md - lg) - 1;
        sl += pos;
        sr -= a[rg - 1];
    }

    ll cl = s[lp] - s[lg];
    ll cr = s[rg] - s[rp];
    sl += cl * 2;
    sr += cr * 2;
    return sr - sl;
}

void tr(int lg, int rg, ll pos) {
    ans = max(ans, eval(lg, rg, pos));
}

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    ll l;
    int n;
    cin >> l >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = l + a[i];
    }

    s[0] = 0;
    for (int i = 0; i < 2 * n;++i) {
        s[i + 1] = s[i] + a[i];
    }

    tr(0, n, 0);

    for (int i = 0; i < n; ++i) {
        tr(i, i + n, l);
    }

    cout << ans << "\n";
}

