#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define ll long long
#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
double const EPS = 1e-12, PI = acos(-1);
const int N = 6e5 + 9, M = 5e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;
const ll inf = 1e18 + 9;

ll arr[M], tree[4*M], tree2[4*M];
int n, k, x, L;

ll query(int node, int start, int end, int lvl, int l, int r) {
    int l_ = L + l;
    int r_ = L + r;
    ll ans = -1;
    while (l_ <= r_) {
        ans = max(ans, tree[l_]);
        ans = max(ans, tree[r_]);
        if ((l_ & 1) == 1) l_++;
        if ((r_ & 1) == 0) r_--;
        l_ >>= 1, r_ >>= 1;
    }
    return ans;
}

void update(int node, int start, int end, int lvl, int idx, ll val) {
    int i = idx + L;
    tree2[i] = max(tree2[i], val);
    while (i != 1) i /= 2, tree2[i] = max(tree2[i * 2], tree2[i * 2 + 1]);
}


int main() {
    fastIO;
    cin >> n >> k >> x;
    L = n; while (L & (L - 1)) L++;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    memset(tree2, -1, sizeof tree2);
    update(1, 0, L - 1, x, 0, 0);
    for (int left = x - 1; left >= 0; --left) {
        swap(tree, tree2);
        memset(tree2, -1, sizeof tree2);
        for (int i = 1; i <= n; ++i) {
            int l = max(0, i - k), r = i - 1;
            ll mx = query(1, 0, L - 1, left + 1, l, r);
            if(mx == -1) continue;
            update(1, 0, L - 1, left, i, mx + arr[i]);
        }
    }
    ll ans = -1;
    swap(tree, tree2);
    for (int i = n - k + 1; i <= n; ++i)
        ans = max(ans, query(1, 0, L - 1, 0, i, i));
    cout << ans;
    return 0;
}