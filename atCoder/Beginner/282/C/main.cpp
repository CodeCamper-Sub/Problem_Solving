#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    cin >> s;
    bool is_enclosed = false;
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '"') {
            is_enclosed = !is_enclosed;
        }
        if(s[i] == ',' && !is_enclosed) {
            s[i] = '.';
        }
    }
    cout << s << '\n';
    return 0;
}