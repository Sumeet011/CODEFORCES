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
    cin >> t;
    while (t--) {
        int n,q;
        cin>>n>>q;
        vector<int> arr = inputArray(n);
        vector<int> brr= inputArray(n);
        for(int i=0;i<n;i++){
            if(arr[i]<brr[i]){
                swap(arr[i],brr[i]);
            }
        }
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                arr[i-1]=arr[i];
            }
        }
        vector<int> prefixSum;
        prefixSum.push_back(0);
        int L=1;
        for(int i=0;i<n;i++){
                prefixSum.push_back(prefixSum[L-1]+arr[i]);
                L+=1;
            
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            l--;
            
                cout<<prefixSum[r]-prefixSum[l]<<" ";
            
        }
        cout<<"\n";

    }
    return 0;
}
