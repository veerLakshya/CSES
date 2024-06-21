#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define MOD 1000000007
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
// dp[1]=dp[0]
// dp[2]=dp[0]+dp[1]
// dp[3]=dp[0]+dp[1]+dp[2]
// ....
// dp[6]=dp[0]+dp[1]+dp[2]+dp[3]+dp[4]+dp[5]+

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= 6;j++) {
            if (j <= i) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
}
// state: dp[k] = no. of ways to get a sum of k
// transition: dp[k] = dp[k-1]+dp[k-2]+dp[k-3]+dp[k-4]+dp[k-5]+dp[k-6]
// base case: dp[0]=1
// final subproblem:  dp[n] = no. of ways to get sum of n
int main() {
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
}