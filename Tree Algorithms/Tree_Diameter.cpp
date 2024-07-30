#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Debug Options-
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
/*---------------------------------------*/

void fleaf(int curr, int parent, vector<vector<int>>& edges, vector<int>& farthestleaf) {
    for (auto neighbour : edges[curr]) {
        if (neighbour != parent) {
            fleaf(neighbour, curr, edges, farthestleaf);
            farthestleaf[curr] = max(farthestleaf[curr], 1 + farthestleaf[neighbour]);
        }
    }
}

void dfs(int curr, int parent, vector<vector<int>>& edges, vector<int>& farthestleaf, vector<int>& longestdist) {
    pair<int, int> p = { -1, -1 };

    for (auto neighbour : edges[curr]) {
        if (neighbour != parent) {
            dfs(neighbour, curr, edges, farthestleaf, longestdist);
            if (p.first == -1) {
                p.first = farthestleaf[neighbour];
            }
            else {
                if (farthestleaf[neighbour] > p.first) {
                    p.second = p.first;
                    p.first = farthestleaf[neighbour];
                }
                else if (farthestleaf[neighbour] > p.second) {
                    p.second = farthestleaf[neighbour];
                }
            }
        }
    }
    longestdist[curr] = p.first + p.second + 2;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> farthestleaf(n, 0);
    vector<int> longestdist(n, 0);
    fleaf(0, -1, adj, farthestleaf);
    dfs(0, -1, adj, farthestleaf, longestdist);

    int ans = 0;
    ans = *max_element(longestdist.begin(), longestdist.end());
    cout << ans << endl;
    return 0;
}