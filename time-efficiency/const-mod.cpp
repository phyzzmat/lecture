#include "iostream"
using namespace std;
const int MOD = 139201923, N = 5e7, c = 12, a = 33;
int MOD2 = 139201923;

int const_mod(int seed) {
    for (int i = 0; i < N; i++) {
        seed = (1ll * a * seed + c) % MOD;
    }
    return seed;
}

int var_mod(int seed) {
    for (int i = 0; i < N; i++) {
        seed = (1ll * a * seed + c) % MOD2;
    }
    return seed;
}

int main() {
    cout << var_mod(0);
}