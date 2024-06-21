#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back

void solve() {
    int n;
    cin >> n;
    vi dp(n + 1);
    // dp[i] = number of ways to make a sum of n such that current sum is i

    // base case
    dp[n] = 1;

    for (int i = n - 1;i >= 0;i--) {
        for (int j = 1;j <= 6;j++) {
            if (j <= n - i) {
                dp[i] = (dp[i] + dp[i + j]) % MOD;
            }
        }
    }

    // final subproblem
    cout << dp[0] << endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
}