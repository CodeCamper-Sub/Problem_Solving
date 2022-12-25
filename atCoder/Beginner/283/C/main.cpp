#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    ll answer = 0;
    for(ll i = 0; i < s.size(); i++) {
        if(s[i] != '0') {
            answer++;
        } else {
            if(i + 1< s.size() && s[i] == '0' && s[i+1] == '0') {
                answer++;
                i++;
            } else {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}