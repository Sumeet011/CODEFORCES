#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int BITS = 31;
    const int MASK = (1 << BITS) - 1;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end());

        vector<bool> used(n, false);
        int Ans = 0;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;

            int x = a[i];
            int opposite = x ^ MASK;

            // binary search for opposite
            int l = lower_bound(a.begin(), a.end(), opposite) - a.begin();

            if (l < n && a[l] == opposite) {
                // find an unused occurrence
                while (l < n && a[l] == opposite && used[l]) l++;
                if (l < n && a[l] == opposite) {
                    used[l] = true;
                }
            }

            used[i] = true;
            Ans++;
        }

        cout << Ans << '\n';
    }

    return 0;
}
