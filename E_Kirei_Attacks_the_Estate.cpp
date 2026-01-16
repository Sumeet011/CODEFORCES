#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> a, mx, mn;
vector<vector<int>> g;

void dfs(int u) {
    for (int v : g[u]) {
        if (mx[v] != -1) continue;   // already visited

        mx[v] = max(a[v], a[v] - mn[u]);
        mn[v] = min(a[v], a[v] - mx[u]);

        dfs(v);
    }
}

void solve() {
    int n;
    cin >> n;

    a.assign(n, 0);
    mx.assign(n, -1);
    mn.assign(n, (ll)2e15);
    g.assign(n, {});

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // root initialization
    mx[0] = a[0];
    mn[0] = a[0];

    dfs(0);

    for (ll x : mx) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
