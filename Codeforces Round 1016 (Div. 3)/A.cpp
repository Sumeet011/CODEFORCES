// ---------- Array Input (Common Patterns) ----------

#include <bits/stdc++.h>
using namespace std;

// 1) Input vector of size n
vector<int> inputArray(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    return a;
}

// 2) Input vector<long long>
vector<long long> inputArrayLL(int n) {
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    return a;
}

// 3) Input static array
void inputStaticArray(int a[], int n) {
    for (int i = 0; i < n; i++) cin >> a[i];
}

// 4) 2D array input (n x m)
vector<vector<int>> input2D(int n, int m) {
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    return a;
}

// 5) Input until EOF
vector<int> inputUntilEOF() {
    vector<int> a;
    int x;
    while (cin >> x) a.push_back(x);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        
    int n;
    cin >> n;
    if(n%2==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }


}
}
