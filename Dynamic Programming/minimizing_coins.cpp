#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

void solve() {
    int n, x; // 1<=n<=100  1<=x<=1e6
    cin >> n >> x;
    vi arr(n);
    for (int i = 0;i < n;i++)cin >> arr[i]; // 1<=arr[i]<=1e6
    vi dp(x + 1, 1e9); // initialized with very high values initially
    // dp[k] = minimum number of coins required to construct a sum of k
    // dp[k] = min(dp[k-ai]) + 1 : i goes from 1  to n
    dp[0] = 0; // base case
    for (int i = 1;i <= x;i++) {
        for (int j = 0;j < n;j++) {
            if (arr[j] <= i)
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
        }
    }
    cout << (dp[x] != 1e9 ? dp[x] : -1);
}

int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
}