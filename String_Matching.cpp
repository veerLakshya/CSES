#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

template<typename T>
void print(vector<T> v) {
    cout << "[ ";
    for (auto i : v) {
        cout << (i);
        cout << " ";
    }
    cout << "]";
}
template<typename T>
void print(set<T> v) {
    cout << "[ ";

    for (auto i : v) {
        cout << (i);
        cout << " ";
    }

    cout << "]";
}
template<typename T>
void print(multiset<T> v) {
    cout << "[ ";

    for (auto i : v) {
        cout << (i);
        cout << " ";
    }

    cout << "]";
}
template<typename T, typename V>
void print(map<T, V> v) {
    cout << "{ ";
    for (auto p : v) {
        cout << p;
        cout << " ";
    }

    cout << "}";
}
template<typename T, typename V>
void print(unordered_map<T, V> v) {
    cout << "{ ";
    for (auto p : v) {
        cout << (p);
        cout << " ";
    }

    cout << "}";
}
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define INF 1e9
#define NINF -1e9
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
//------------------------------------------------------------------------------------

ll const B1 = 5689;
ll const B2 = 8861;

void solve() {
    string s, p;
    cin >> s >> p;
    int n = s.size(), m = p.size();
    ll hash1_p = 1, hash2_p = 1;
    for (int i = 0;i < m;i++) {
        hash1_p = ((hash1_p * B1) % MOD + (p[i] - 'a' + 1)) % MOD;
        hash2_p = ((hash2_p * B2) % MOD + p[i] - 'a' + 1) % MOD;
    }
    vector<pair<ll, ll>> hashes(n + 1, { 1,1 }), powers(n + 1, { 1,1 });
    for (int i = 0; i < n; i++) {
        hashes[i + 1].ff = ((hashes[i].ff * B1) % MOD + s[i] - 'a' + 1) % MOD;
        hashes[i + 1].ss = ((hashes[i].ss * B2) % MOD + s[i] - 'a' + 1) % MOD;
        powers[i + 1].ff = (powers[i].ff * B1) % MOD;
        powers[i + 1].ss = (powers[i].ss * B2) % MOD;
    }
    ll ans = 0;
    for (ll i = m - 1; i < n; i++) {
        ll hash1 = (hashes[i + 1].ff - (hashes[i - m - 1].ff * powers[i - m + 1].ff) % MOD + MOD) % MOD;
        ll hash2 = (hashes[i + 1].ss - (hashes[i - m - 1].ss * powers[i - m + 1].ss) % MOD + MOD) % MOD;
        if (hash1 == hash1_p && hash2 == hash2_p) {
            ans++;
        }
    }
    cout << ans << endl;

}

int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}