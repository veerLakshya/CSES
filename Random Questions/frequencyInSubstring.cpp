#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> pref(n + 1, vector<int>(26));
    // pref[i][j] = frequency of jth character in substring s[0...i-1]
    // pref[5][0]=3 means frequency of 'a' in s[0...4] is 3
    for (int i = 0;i < n;i++) {
        pref[i + 1] = pref[i];//copying previous values
        int char_id = s[i] - 'a'; // converting character to integer 0...25
        pref[i + 1][char_id]++; // incrementing frequency of that character
    }

    //reading queries
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        char best_char = '?';
        int best_freq = -1;
        for (int char_id = 0;char_id < 26;char_id++) {
            int freq = pref[r + 1][char_id] - pref[l][char_id];
            if (freq > best_freq) {
                best_freq = freq;
                best_char = char_id + 'a';
            }
        }
        cout << best_char << " " << best_freq << endl;
    }
}

// Time complexity of this code is O(26*n+q*26) where n is the length of string and q is the number of queries