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

// V2 - PAC
#include <bits/stdc++.h>

using namespace std;

#define maxN 1000005

int n, k;
int a[maxN];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n - k + 1; ++i) {
        int ans = a[i];
        for (int j = i + 1; j <= i + k - 1; ++j) {
            ans = min(ans, a[j]);
        }
        cout << ans << " ";
    }
    cout << "\n";
    return 0;
}
