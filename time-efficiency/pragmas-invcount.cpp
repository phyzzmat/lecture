#include<bits/stdc++.h>
using namespace std;
int a[50000] = {}, m, n;

signed main() {
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int invs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) invs += (a[j] > a[i]);
    }
    cout << invs;
}