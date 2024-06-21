#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p = 10e9 + 7;
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1;i <= n;i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }

    return 0;
}
