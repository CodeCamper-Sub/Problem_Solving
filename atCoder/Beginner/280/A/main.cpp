#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll H, W;
    string s;
    cin >> H >> W;
    ll answer = 0;
    for(ll i = 0; i < H; i++) {
        cin >> s;
        for(ll j = 0; j < s.size(); j++){ 
            if(s[j] == '#') answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}