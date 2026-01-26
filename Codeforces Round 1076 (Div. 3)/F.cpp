#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

vector<int> inputArray(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}

vector<long long> inputArrayLL(int n) {
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}

void inputStaticArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
}

vector<vector<int>> input2D(int n, int m) {
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    return mat;
}

vector<int> inputUntilEOF() {
    vector<int> res;
    int val;
    while (cin >> val) res.push_back(val);
    return res;
}
void solve() {
    int cnt;
    cin >> cnt;
    
    long long sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    
    vector<pair<int, int>> coords(cnt);
    for (int i = 0; i < cnt; ++i) cin >> coords[i].first;
    for (int i = 0; i < cnt; ++i) cin >> coords[i].second;
    
    map<int, vector<int>> col;
    for (auto &pt : coords) {
        col[pt.first].push_back(pt.second);
    }
    
    long long best[2] = {0, 0};
    long long lastY[2] = {sy, sy};
    
    for (auto &it : col) {
        auto &vals = it.second;
        
        long long low = vals[0], high = vals[0];
        for (int v : vals) {
            low = min(low, (long long)v);
            high = max(high, (long long)v);
        }
        
        long long span = high - low;
        
        long long reachHigh = min(
            best[0] + llabs(lastY[0] - high),
            best[1] + llabs(lastY[1] - high)
        );
        
        long long reachLow = min(
            best[0] + llabs(lastY[0] - low),
            best[1] + llabs(lastY[1] - low)
        );
        
        long long next0 = reachHigh + span;
        long long next1 = reachLow + span;
        
        best[0] = next0;
        best[1] = next1;
        lastY[0] = low;
        lastY[1] = high;
    }
    
    long long vertical = min(
        best[0] + llabs(lastY[0] - ey),
        best[1] + llabs(lastY[1] - ey)
    );
    
    cout << vertical + (ex - sx) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}k