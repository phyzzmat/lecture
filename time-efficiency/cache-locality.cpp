#include<bits/stdc++.h>
using namespace std;
const short int L = 22;

const int N = 1000000;
int parent[N + 1], anc[L][N + 1], d[N + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    int n;
    cin >> n;
    anc[0][1] = 1;
    d[1] = 0;
    while(n--) {
        string q; int a, b;
        cin >> q >> a >> b;
        if (q == "ADD") {
            parent[b] = anc[0][b] = a;
            d[b] = d[a] + 1;
            for (int i = 1; i < L; i++) anc[i][b] = anc[i - 1][anc[i - 1][b]];
        }
        else {

            if (d[a] > d[b]) swap(a, b);
            int i = L;
            while(i--) if (d[b] - d[a] >= (1 << i)) b = anc[i][b];

            if (a == b) cout << a << '\n';
            else {
                for (int i = L - 1; i >= 0; i--) {
                    if (anc[i][a] != anc[i][b]) a = anc[i][a], b = anc[i][b];
                }
                cout << parent[a] << '\n';
            }
        }
    }
}