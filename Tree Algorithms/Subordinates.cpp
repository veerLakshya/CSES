#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Debug Options-
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
/*---------------------------------------*/

void dfs(int currNode, int parentNode, vector<vector<int>>& edges, vector<int>& children) {
    for (auto neighbour : edges[currNode]) {
        if (neighbour != parentNode) {
            children[currNode]++;
            dfs(neighbour, currNode, edges, children);
            children[currNode] += children[neighbour];
        }
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> edges(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        edges[i].push_back(x);
        edges[x].push_back(i);
    }
    // using dfs and root as 1
    vector<int> children(n + 1, 0);
    dfs(1, -1, edges, children);
    for (int i = 1; i <= n; i++) {
        cout << children[i] << " ";
    }
    return 0;
}