#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        string s;
        ll is_possible = false;
        set<string> ss[5];
        for(ll i = 0; i < n; i++) {
            cin >> s;
            if(is_possible) continue;
            if(s.size() == 1) {
                is_possible = true;
            } else if(s.size() == 2){
                if(s[0] == s[1]) {
                    is_possible = true;
                } else {
                    string inversed = s;
                    reverse(inversed.begin(), inversed.end());
                    if(ss[2].find(inversed) != ss[2].end()) {
                        is_possible = true;
                    }
                    if(ss[1].find(inversed) != ss[1].end()) {
                        is_possible = true;
                    }
                }
                ss[2].insert(s);
            } else if(s.size() == 3) {
                if(s[0] == s[2]) {
                    is_possible = true;
                } else {
                    string inversed = s;
                    reverse(inversed.begin(), inversed.end());
                    if(ss[3].find(inversed) != ss[3].end()) {
                        is_possible = true;
                    }
                    if(ss[2].find(inversed.substr(0, 2)) != ss[2].end()) {
                        is_possible = true;
                    }
                }
                ss[3].insert(s);
                ss[1].insert(s.substr(0, 2));
            }
        }
        if(is_possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}