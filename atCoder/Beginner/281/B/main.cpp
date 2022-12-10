#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string s;

bool is_uppercase_letter(char c) {
    if(c >= 'A' && c <= 'Z') {
        return true;
    } else {
        return false;
    }
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    if(s.size() != 8) {
        cout << "No" << '\n';
        return 0;
    }
    if(!is_uppercase_letter(s[0])) {
        cout << "No" << '\n';
        return 0;
    }
    for(ll i = 1; i < s.size() - 1; i++) {
        if(!is_digit(s[i])) {
            cout << "No" << '\n';
            return 0;
        } else if (i == 1 && s[i] == '0') {
            cout << "No" << '\n';
            return 0;
        }
    }
    if(!is_uppercase_letter(s[s.size()-1])) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    return 0;
}