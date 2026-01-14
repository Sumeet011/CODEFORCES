#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;
    long long total = 0;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void activate(int x) {
        sz[x] = 1;
        total += 1; // 1*(1+1)/2 = 1
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        total -= 1LL * sz[a] * (sz[a] + 1) / 2;
        total -= 1LL * sz[b] * (sz[b] + 1) / 2;

        parent[b] = a;
        sz[a] += sz[b];

        total += 1LL * sz[a] * (sz[a] + 1) / 2;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> T(n);
        for (int i = 0; i < n; i++) cin >> T[i];

        vector<pair<int,int>> A;
        for (int i = 1; i < n; i++) {
            A.push_back({abs(T[i] - T[i-1]), i});
        }

        sort(A.rbegin(), A.rend());

        vector<long long> ans(n, 0);
        vector<bool> active(n, false);
        DSU dsu(n);

        int ptr = 0;
        for (int d = n - 1; d >= 1; d--) {
            while (ptr < (int)A.size() && A[ptr].first >= d) {
                int idx = A[ptr].second;
                active[idx] = true;
                dsu.activate(idx);

                if (idx > 1 && active[idx - 1]) dsu.unite(idx, idx - 1);
                if (idx < n - 1 && active[idx + 1]) dsu.unite(idx, idx + 1);

                ptr++;
            }
            ans[d] = dsu.total;
        }

        for (int d = 1; d < n; d++) {
            cout << ans[d] << " ";
        }
        cout << "\n";
    }
}
