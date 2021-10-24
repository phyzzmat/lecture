#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
gp_hash_table<int, int> table;
unordered_map<int, int> table2;

const int N = 1e7, MAX = 1 << 15;
int main() {
    for (int i = 0; i < N; i++) {
        table[rand() & (MAX - 1)]++;
    }
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += table[rand() & (MAX - 1)];
    }
    cout << sum;
}