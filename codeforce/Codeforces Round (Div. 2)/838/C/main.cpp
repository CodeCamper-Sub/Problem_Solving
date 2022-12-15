#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 998244353
typedef long long ll;
using namespace std;

ll tt;
ll n, answer;
string s;
ll dp[200200];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;
    while(tt--) {
        cin >> n;
        cin >> s;
        dp[0] = 1;
        for(ll i = 1; i < s.size(); i++) {
            if(s[i] != s[i-1]) {
                dp[i] = 1;
            } else {
                dp[i] = dp[i-1] * 2 % MOD;
            }
        }
        answer = 0;
        for(ll i = 0; i < n; i++) {
            answer += dp[i];
            answer %= MOD;
        }
        cout << answer << '\n';
    }

    return 0;
}