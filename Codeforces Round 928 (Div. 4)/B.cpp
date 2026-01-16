#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> M(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++) {
                M[i][j] = row[j] - '0';
            }
        }

        vector<vector<int>> rowMap(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    cnt++;
                } else {
                    if (cnt > 0) rowMap[i].push_back(cnt);
                    cnt = 0;
                }
            }
            if (cnt > 0) rowMap[i].push_back(cnt);
        }

        set<int> distinctLengths;
        for (int i = 0; i < n; i++) {
            for (int len : rowMap[i]) {
                distinctLengths.insert(len);
            }
        }

        if (distinctLengths.size() > 1)
            cout << "TRIANGLE\n";
        else
            cout << "SQUARE\n";
    }

    return 0;
}
