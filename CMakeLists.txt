#include <bits/stdc++.h>

using namespace std;

const long long k = 450;

struct nd{
    long long l, r, x, y, ind;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (long long i = 0; i < n; ++i) {
        cin >> b[i];
    }
    cin >> m;
    vector<long long> res(n, -1), razn2(n + 2);
    for (long long i = 0; i < n; ++i) {
        if (a[i] >= b[i]) {
            res[i] = 0;
        }
    }
    vector<nd> qs;
    for (long long q = 0; q < m; ++q) {
        long long ll, rr, x, y;
        cin >> ll >> rr >> x >> y;
        --ll, --rr;
        qs.push_back({ll, rr, x, y, q});
        if ((q + 1) % k == 0 || q == m - 1) {
            vector<long long> d(n);
            for (long long i = 0; i < (long long)qs.size(); ++i) {
                long long l = qs[i].l + 1, r = qs[i].r + 1, d = qs[i].y;
                razn2[l] += d;
                razn2[qs[i].l] += qs[i].x;
                razn2[qs[i].l + 1] -= qs[i].x;
                razn2[qs[i].r + 1] -= qs[i].x;
                razn2[qs[i].r + 2] += qs[i].x;
                if (r < n) {
                    razn2[r] -= (r - l + 1) * d;
                }
                if (r < n - 1) {
                    razn2[r + 1] += (r - l) * d;
                }
            }
            d[0] = razn2[0];
            for (long long i = 1; i < n; ++i) {
                d[i] = d[i - 1] + razn2[i];
            }
            for (long long i = 1; i < n; ++i) {
                d[i] += d[i - 1];
            }
            for (long long i = 0; i < n; ++i) {
                if (res[i] == -1 && a[i] + d[i] >= b[i]) {
                    long long add = 0;
                    for (auto & qq : qs) {
                        if (qq.l > i || qq.r < i) continue;
                        long long curadd = qq.x + qq.y * (i - qq.l);
                        add += curadd;
                        if (a[i] + add >= b[i]) {
                            res[i] = qq.ind + 1;
                            break;
                        }
                    }
                }
            }
            for (long long i = 0; i < n; ++i) {
                a[i] += d[i];
            }
            razn2.assign(n + 2, 0);
            qs.clear();
        }
    }
    for (auto& el : res) {
        cout << el << " ";
    }
}
