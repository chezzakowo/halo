#include <bits/stdc++.h>

using namespace std;

#define maxN 100005

struct MyStack {
    int data[maxN];
    int top_idx = 0;

    void push(int x) {
        if (top_idx == 100000) return;

        ++top_idx;
        data[top_idx] = x;
    }

    int top() {
        if (top_idx == 0) return -1;
        return data[top_idx];
    }

    void pop() {
        if (top_idx == 0) return;
        --top_idx;
    }

    bool empty() {
        return top_idx == 0;
    }

    void reset() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    int n;
    int a[maxN];
    MyStack q;

    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> a[i];

    int pos = 1;

    for (int i = 1; i <= n; ++i) {
        while (pos <= n && (q.empty() || q.top() != a[i])) {
            q.push(pos);
            pos++;
        }

        if (q.empty() || q.top() != a[i]) {
            cout << "NO" << "\n";
            return 0;
        }

        q.pop();
    }
    cout << "YES" << "\n";
}
