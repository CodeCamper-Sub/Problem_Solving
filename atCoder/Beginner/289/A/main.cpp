#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '0') {
            cout << 1;
        } else {
            cout << 0;
        }
    }

    return 0;
}