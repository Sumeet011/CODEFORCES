// ==============================
// Commonly Used C++ Snippet
// ==============================

#include <bits/stdc++.h>
using namespace std;

// ---------- Type Aliases ----------
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;

// ---------- Constants ----------
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

// ---------- Fast IO ----------
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ---------- Math Utilities ----------
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll modAdd(ll a, ll b) { return (a + b) % MOD; }
ll modSub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll modMul(ll a, ll b) { return (a * b) % MOD; }

ll modPow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = modMul(res, a);
        a = modMul(a, a);
        b >>= 1;
    }
    return res;
}

// ---------- Prime Check ----------
bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// ---------- Sieve ----------
vector<int> sieve(int n) {
    vector<int> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= n; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
    return prime;
}

// ---------- Prefix Sum ----------
vector<ll> prefixSum(const vector<ll>& a) {
    int n = a.size();
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    return pref;
}

// ---------- Binary Search Helpers ----------
int lowerIndex(const vector<int>& a, int x) {
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int upperIndex(const vector<int>& a, int x) {
    return upper_bound(a.begin(), a.end(), x) - a.begin();
}

// ---------- Sorting ----------
void sortAsc(vector<int>& a) { sort(a.begin(), a.end()); }
void sortDesc(vector<int>& a) { sort(a.rbegin(), a.rend()); }

// ---------- Min / Max ----------
template<typename T>
T getMin(const vector<T>& a) { return *min_element(a.begin(), a.end()); }

template<typename T>
T getMax(const vector<T>& a) { return *max_element(a.begin(), a.end()); }

// ---------- Debug ----------
template<typename T>
void printVec(const vector<T>& a) {
    for (auto &x : a) cout << x << " ";
    cout << "\n";
}

// 1) Input vector of size n
vector<int> inputArray(int n) {
    int m=-1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {cin >> a[i]; m=max(m,a[i]);}
    a.push_back(m);
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


bool check(int x, vector<int>& a, int n, int k) {
    if (x == 0) return true; // mex >= 0 always possible

    vector<int> cnt(x, 0);
    int need = x;   // how many numbers from [0..x-1] still missing
    int segments = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < x) {
            if (cnt[a[i]] == 0) {
                cnt[a[i]] = 1;
                need--;
            }
        }

        if (need == 0) {
            segments++;
            if (segments >= k) return true;

            // reset for next segment
            fill(cnt.begin(), cnt.end(), 0);
            need = x;
        }
    }

    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int L = 0, R = n + 1; // mex cannot exceed n
        int ans = 0;

        while (R - L > 1) {
            int mid = (L + R) / 2;
            if (check(mid, a, n, k)) {
                ans = mid;
                L = mid;
            } else {
                R = mid;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
