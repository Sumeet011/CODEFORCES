#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(long long x, long long y, long long k) {
    if (y < x) return -1;
    if (y % x != 0) return -1;

    long long d = y / x;
    int ops = 0;

    while (d > 1) {
        bool found = false;
        for (long long a = min(k, d); a >= 2; a--) {
            if (d % a == 0) {
                d /= a;
                ops++;
                found = true;
                break;
            }
        }
        if (!found) return -1;
    }
    return ops;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x,y,k;
        cin>>x>>y>>k;
        cout<<solve(x,y,k);

    }
}
