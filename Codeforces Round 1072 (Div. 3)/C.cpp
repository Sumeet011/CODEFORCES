#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k > n) {
            cout << -1 << "\n";
            continue;
        }

        queue<pair<long long, int>> q;
        unordered_set<long long> vis;

        q.push(make_pair(n, 0));
        vis.insert(n);

        int answer = -1;

        while (!q.empty()) {
            pair<long long, int> cur = q.front();
            q.pop();

            long long x = cur.first;
            int steps = cur.second;

            if (x == k) {
                answer = steps;
                break;
            }

            if (x % 2 == 0) {
                long long a = x / 2;
                if (a >= k && vis.find(a) == vis.end()) {
                    vis.insert(a);
                    q.push(make_pair(a, steps + 1));
                }
            } else {
                long long a = x / 2;
                long long b = (x + 1) / 2;

                if (a >= k && vis.find(a) == vis.end()) {
                    vis.insert(a);
                    q.push(make_pair(a, steps + 1));
                }
                if (b >= k && vis.find(b) == vis.end()) {
                    vis.insert(b);
                    q.push(make_pair(b, steps + 1));
                }
            }
        }

        cout << answer << "\n";
    }

}
