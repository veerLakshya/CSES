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

bool possible(ll x, vll v, ll k, ll n) {
    ll noOfDivisions = k;
    ll currentSize = 0;
    rep(i, 0, n) {
        if (v[i] > x)return false;
        if (v[i] + currentSize <= x) {
            currentSize += v[i];
        }
        else {
            currentSize = v[i];
            k--;
            if (k < 0)return false;
        }
    }
    return true;

}


int main()
{
    ll n, k;
    cin >> n >> k;
    k--;
    vll v(n);
    ll sum = 0;
    rep(i, 0, n) {
        cin >> v[i];
        sum += v[i];
    }

    ll left = 0, right = sum;
    ll ans = 1e6;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (possible(mid, v, k, n)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    pr(ans);
}