#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll sieve[200200], dp[200200], n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(sieve, sieve + 200200, -1);
    for(ll i = 2; i <= 200000; i++) {
        if(sieve[i] == -1) {
            for(ll j = 1; i * j <= 200000; j++) {
                sieve[i * j] = i;
            }
        }
    }

    dp[1] = 1;
    for(ll i = 2; i <= 200000; i++) {
        ll now = i;
        vector<ll> dividers;
        while(now > 1) {
            dividers.push_back(sieve[now]);
            now /= sieve[now];
        }
        sort(dividers.begin(), dividers.end());
        ll cnt = 0;
        dp[i] = 1;
        for(ll j = 0; j < dividers.size(); j++) {
            cnt++;
            if(j == dividers.size() - 1 || dividers[j] != dividers[j+1]) {
                dp[i] *= cnt + 1;
                cnt = 0;
            }
        }
    }

    cin >> n;

    ll answer = 0;
    for(ll i = 1; i < n; i++) {
        answer += dp[i] * dp[n-i];
    }

    cout << answer << '\n';

    return 0;
}