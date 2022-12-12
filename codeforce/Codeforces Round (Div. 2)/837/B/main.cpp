#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, n, m, x, y, answer;
ll dp[100100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> tt;

    while(tt--) {
        cin >> n >> m;
        answer = 0;
        for(ll i = 1; i <= n; i++) dp[i] = n + 1;
        for(ll i = 0; i < m; i++) {
            cin >> x >> y;
            if(x > y) swap(x, y);
            dp[x] = min(dp[x], y);
        }
        ll last = n-1;
        for(ll i = n; i >= 1; i--) {
            answer += i - last;
            for(ll j = last; j >= 1; j--) {
                last = j;
                if(dp[j] > i) {
                    answer++;
                } else {
                    break;
                }
            }
        }
        cout << answer << '\n';
    }

    return 0;
}