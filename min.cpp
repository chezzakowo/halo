#include <bits/stdc++.h>

#define maxN 1000005
#define oo 1000000007

using namespace std;

int a[maxN];
deque<int> dq;

int main() {
    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        while (!dq.empty() && dq.front() <= i-k) {
            dq.pop_front();
        }

        while(!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k) {
            cout << a[dq.front()] << " ";
        }
    }

    cout << "\n";
    return 0;
}
