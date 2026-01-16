#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int Ca = 0, Cb = 0;

        for (char c : s) {
            if (c == 'A') {
                Ca++;
            } else if (c == 'B') {
                Cb++;
            }
        }

        if (Ca > Cb) {
            cout << 'A' << endl;
        } else {
            cout << 'B' << endl;
        }
    }

    return 0;
}
