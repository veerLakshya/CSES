#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);     // 0 based indexing
    for (int i = 0;i < n;i++)cin >> arr[i];

    vector<long long> prefix(n + 1, 0);   // 1 based indexing
    for (int i = 1;i <= n;i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    //prefix[0]=0
    //prefix[1]=arr[0]
    //prefix[2]=arr[0]+arr[1]
    //prefix[i] = arr[0]+arr[1]+arr[2]+....+arr[i-1]

    for (int i = 0;i < q;i++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}
