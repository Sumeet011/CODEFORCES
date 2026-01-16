#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<ll> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        // Prefix arrays
        vector<ll> prefMinX(n), prefMaxX(n), prefMinY(n), prefMaxY(n);
        vector<ll> sufMinX(n),  sufMaxX(n),  sufMinY(n),  sufMaxY(n);

        // Build prefix
        prefMinX[0] = prefMaxX[0] = x[0];
        prefMinY[0] = prefMaxY[0] = y[0];

        for (int i = 1; i < n; i++) {
            prefMinX[i] = min(prefMinX[i-1], x[i]);
            prefMaxX[i] = max(prefMaxX[i-1], x[i]);
            prefMinY[i] = min(prefMinY[i-1], y[i]);
            prefMaxY[i] = max(prefMaxY[i-1], y[i]);
        }

        // Build suffix
        sufMinX[n-1] = sufMaxX[n-1] = x[n-1];
        sufMinY[n-1] = sufMaxY[n-1] = y[n-1];

        for (int i = n-2; i >= 0; i--) {
            sufMinX[i] = min(sufMinX[i+1], x[i]);
            sufMaxX[i] = max(sufMaxX[i+1], x[i]);
            sufMinY[i] = min(sufMinY[i+1], y[i]);
            sufMaxY[i] = max(sufMaxY[i+1], y[i]);
        }

        // Initial rectangle with all monsters
        ll Ans = (prefMaxX[n-1] - prefMinX[n-1] + 1) *
                 (prefMaxY[n-1] - prefMinY[n-1] + 1);

        // Try removing each monster
        for (int i = 0; i < n; i++) {
            ll minX, maxX, minY, maxY;

            if (i == 0) {
                minX = sufMinX[1];
                maxX = sufMaxX[1];
                minY = sufMinY[1];
                maxY = sufMaxY[1];
            } else if (i == n - 1) {
                minX = prefMinX[n-2];
                maxX = prefMaxX[n-2];
                minY = prefMinY[n-2];
                maxY = prefMaxY[n-2];
            } else {
                minX = min(prefMinX[i-1], sufMinX[i+1]);
                maxX = max(prefMaxX[i-1], sufMaxX[i+1]);
                minY = min(prefMinY[i-1], sufMinY[i+1]);
                maxY = max(prefMaxY[i-1], sufMaxY[i+1]);
            }

            ll area = (maxX - minX + 1) * (maxY - minY + 1);
            if(area>=n){
                Ans=min(Ans,area);
            }
            else{
                Ans=min(Ans,min((maxX - minX + 2) * (maxY - minY + 1),
                               (maxX - minX + 1) * (maxY - minY + 2)));
            }
        }

        cout << Ans << "\n";
    }
    return 0;
}
