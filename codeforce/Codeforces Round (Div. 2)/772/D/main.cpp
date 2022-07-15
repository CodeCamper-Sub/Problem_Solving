#include <bits/stdc++.h>
#define MODULAR 1000000007
typedef long long ll;
using namespace std;

ll n, p, a, sum;
vector<ll> v;
set<ll> s;
ll dp[200200];

ll bit_suffix(ll num) {
    while(num != 1) {
        if (num % 2) {
            num /= 2;
        }
        else if ( num % 4 == 0 ) {
            num /= 4;
        }
        else {
            break;
        }
    }
    return num;
}

ll number_of_digit(ll num) {
    ll digit = 0;
    while(num != 0) {
        digit++;
        num /= 2;
    }
    return digit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++ ) {
        ll num = v[i];
        while (num != 0) {
            if (s.find(num) != s.end()) {
                break;
            }
            else if ( num % 2 ) {
                num /= 2;
            }
            else if ( num % 4 == 0) {
                num /= 4;
            }
            else {
                s.insert(v[i]);
                dp[number_of_digit(v[i])]++;
                break;
            }
        }
        if ( num == 0 ) {
            s.insert(v[i]);
            dp[number_of_digit(v[i])]++;
        }
    }

    dp[2] = (dp[2] + dp[1]) % MODULAR;
    for (int i = 3; i <= p; i++) {
        dp[i] = (dp[i] + dp[i-1]) % MODULAR;
        dp[i] = (dp[i] + dp[i-2]) % MODULAR;
    }

    for (int i = 1; i <= p; i++) {
        sum = (sum + dp[i]) % MODULAR;
    }

    cout << sum;

    return 0;
}