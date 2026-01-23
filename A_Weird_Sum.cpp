#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int,int>>> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            mp[x].push_back({i, j});
        }
    }

    long long ans = 0;

    for (auto &kv : mp) {
        auto &v = kv.second;
        int k = v.size();
        if (k <= 1) continue;

        vector<long long> rows, cols;
        for (auto &p : v) {
            rows.push_back(p.first);
            cols.push_back(p.second);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        // Row contribution
        long long pref = 0;
        for (int i = 0; i < k; i++) {
            ans += rows[i] * i - pref;
            pref += rows[i];
        }

        // Column contribution
        pref = 0;
        for (int i = 0; i < k; i++) {
            ans += cols[i] * i - pref;
            pref += cols[i];
        }
    }

    cout << ans << "\n";
    return 0;
}
