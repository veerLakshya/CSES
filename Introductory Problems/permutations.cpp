#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unordered_map<int, int> umi;
typedef unordered_map<ll, ll> uml;
typedef map<int, int> mi;
typedef map<ll, ll> mll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pair<int, int>> vii;


#define rep(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define repll(a, b, c) for (ll(a) = (b); (a) < (c); ++(a))
#define repn(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define repnll(a, b, c) for (ll(a) = (b); (a) <= (c); ++(a))
#define repd(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define repdll(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define repsq(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define repsqll(a, b, c) for (ll(a) = (b); (a) * (a) <= (c); ++(a))
#define foreach(a, b) for (auto&(a) : (b))
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define alla(arr, sz) arr, arr + sz
#define sz(a) ((int)a.size())
#define SORT(v) sort(all(v))
#define REVERSE(v) reverse(all(v))
#define SORTA(arr, sz) sort(alla(arr, sz))
#define REVERSEA(arr, sz) reverse(alla(arr, sz))
inline ll getll() { ll a; scanf("%lld", &a); return a; }
inline int geti() { int a; scanf("%d", &a); return a; }
#define pr(a) cout<<a
#define prs(a) cout<<a<<" "
#define prn(a) cout<<a<<"\n"
#define br cout<<"\n"
#define yes cout<<"yes"
#define no cout<<"no"
#define TC(t) while (t--)



int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        pr(1);
        return 0;
    }
    if (n == 2 || n == 3) {
        pr("NO SOLUTION");
        return 0;
    }
    if (n % 2 == 0) {
        for (int i = 2;i <= n;i += 2)
            prs(i);
        for (int i = 1;i < n;i += 2)
            prs(i);
    }
    else {
        for (int i = n - 1; i > 0; i -= 2)
            prs(i);
        for (int i = n; i > 0; i -= 2)
            prs(i);
    }

}
// (1)5(2)6(3)7(4)8
//  0 1 2 3 4 5 6 7
// (1)4(2)5(3)
// 31425