#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s, t;

ll no_matching_cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;

    for(ll i = 0; i < t.size(); i++) {
        ll s_index = s.size()-t.size() + i;
        if(s[s_index] == '?' || t[i] == '?') 
            continue;
        else if(s[s_index] != t[i]) {
            no_matching_cnt++;
        }
    }
    if(no_matching_cnt == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    for(ll i = 0; i < t.size(); i++) {
        ll s_index = s.size() - t.size() + i;
        if(s[s_index] != '?' && t[i] != '?' && s[s_index] != t[i]) {
            no_matching_cnt -= 1;
        }
        if(s[i] != '?' && t[i] != '?' && s[i] != t[i]) {
            no_matching_cnt++;
        }
        if(no_matching_cnt == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    

    return 0;
}