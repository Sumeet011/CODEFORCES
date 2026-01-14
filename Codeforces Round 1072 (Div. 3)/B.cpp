#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int s, k, m;
        cin >> s >> k >> m;

        if (k == s) {
            cout << s - (m - (m / s) * s) << endl;
        }
        else if (k > s) {
            m -= (m / k) * k;
            if (m <= s) {
                cout << s - m << endl;
            } else {
                cout << 0 << endl;
            }
        }
        else {
            if((m/k)%2==0){
                
            m -= (m / k) * k;
                cout << s-m << endl;
            }
            else{
                
            m -= (m / k) * k;
                cout << k-m << endl;

            }
        }
    }

    return 0;
}
