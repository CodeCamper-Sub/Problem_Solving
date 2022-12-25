#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;
ll alpha[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;

    bool is_possible = true;

    for(ll i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            for(ll i = 0; i < 26; i++) {
                if(alpha[i] > 0) {
                    alpha[i] += 1;
                }
            }
        } else if(s[i] == ')') {
            for(ll i = 0; i < 26; i++) {
                if(alpha[i] > 0) {
                    alpha[i] -= 1;
                }
            }
        } else {
            if(alpha[s[i]-'a'] > 0) {
                is_possible = false;
                break;
            } else {
                alpha[s[i]-'a']++;
            }
        }
    }
    if(is_possible) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}