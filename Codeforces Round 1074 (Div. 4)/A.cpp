#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    int num_leaves = 1 << n;
    

    vector<int> tree(2 * num_leaves);


    // Store them directly into the leaf positions
    for (int i = 0; i < num_leaves; ++i) {
        cin >> tree[num_leaves + i];
    }


    for (int i = num_leaves - 1; i > 0; --i) {
        tree[i] = tree[2 * i] ^ tree[2 * i + 1];
    }

    for (int i = 0; i < q; ++i) {
        int b;
        int c;
        cin >> b >> c;

        int cow_idx = b - 1;
        int curr = num_leaves + cow_idx;

        int delta = tree[curr] ^ c;

        int ans = 0;

        for (int k = 0; k < n; ++k) {

            
            bool is_left_child = (curr % 2 == 0);
            int sibling = is_left_child ? curr + 1 : curr - 1;

            int my_val = tree[curr] ^ delta;
            int sib_val = tree[sibling];

            bool i_win = false;

            if (is_left_child) {

                if (my_val >= sib_val) i_win = true;
            } else {

                if (my_val > sib_val) i_win = true;
            }

            if (!i_win) {
                ans += (1 << k);
            }

            curr /= 2;
        }

        cout << ans << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}