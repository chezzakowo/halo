#include <bits/stdc++.h>

using namespace std;

#define maxN 500005

struct MyStack {
    int data[maxN];
    int top_idx = 0;

    void push(int x) {
        if (top_idx == 500000) return;

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

long long h[maxN];
long long p[maxN];
long long ans[maxN];

int main() {
    int n;
    MyStack q;
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];

    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && h[q.top()] < h[i]) {
            int j = q.top();
            q.pop();

            ans[i] += p[j];
        }

        if (!q.empty()) {
            int j = q.top();
            ans[i] += p[j];
        }

        q.push(i);
    }

    q.reset();

    for (int i = n; i >= 1; --i) {
        while (!q.empty() && h[q.top()] < h[i]) {
            int j = q.top();
            q.pop();

            ans[i] += p[j];
        }

        if (!q.empty()) {
            int j = q.top();
            ans[i] += p[j];
        }

        q.push(i);
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
