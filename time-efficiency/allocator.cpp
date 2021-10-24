#include <bits/stdc++.h>

const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];

void *operator new(size_t n) {
    assert((mpos += n) <= MAX_MEM);
    return (void *) (mem + mpos - n);
}

void operator delete(void *) noexcept {}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    priority_queue<int, vector<int>, greater<>> heap;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string op;
            cin >> op;
            if (op == "Insert") {
                int x;
                cin >> x;
                heap.push(x);
            } else if (op == "GetMin") {
                cout << heap.top() << "\n";
            } else if (op == "EraseMin") {
                heap.pop();
            }
        }
        while (!heap.empty()) heap.pop();
    }
    return 0;
}