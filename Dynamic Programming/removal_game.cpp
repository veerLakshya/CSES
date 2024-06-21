#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5000;
int a[N], dp[N][N], n;

const int INF = -1e18;

int f(int i, int j) {
    if (i > j) return 0;
    if (i == j) return a[i];
    if (dp[i][j] != INF) return dp[i][j];
    int left = a[i] + min(f(i + 1, j - 1), f(i + 2, j));
    int right = a[i] + min(f(i + 1, j - 1), f(i, j - 2));
    return dp[i][j] = max(left, right);
}

signed main() {
    // memset(dp, INF, sizeof(dp));
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            dp[i][j] = INF;
    cin >> n;
    for (int i = 0;i < n;i++)cin >> a[i];
    cout << f(0, n - 1) << endl;
}