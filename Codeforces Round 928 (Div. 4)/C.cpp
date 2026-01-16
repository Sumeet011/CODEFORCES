#include <bits/stdc++.h>
using namespace std;

string s;
long long dp[20][200][2];
bool vis[20][200][2];

long long solve(int pos, int sum, int tight) {
    if (pos == (int)s.size()) {
        return sum;
    }

    if (vis[pos][sum][tight])
        return dp[pos][sum][tight];

    vis[pos][sum][tight] = true;
    long long res = 0;

    int limit = tight ? (s[pos] - '0') : 9;

    for (int d = 0; d <= limit; d++) {
        res += solve(
            pos + 1,
            sum + d,
            tight && (d == limit)
        );
    }

    return dp[pos][sum][tight] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        s = to_string(n);
        memset(vis, false, sizeof(vis));

        cout << solve(0, 0, 1) << "\n";
    }
    return 0;
}
