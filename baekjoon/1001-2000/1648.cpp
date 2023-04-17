#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 9901
typedef long long ll;
using namespace std;

ll n, m;
ll dp[200][1 << 15];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  if((n * m) % 2) {
    cout << 0 << '\n';
    return 0;
  }

  dp[0][0] = 1;

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      ll idx = i * m + j;
      for(ll status = 0; status < (1 << m); status++) {
        if(status & (1 << 0)) {
          // 이미 채워져 있는 상태
          ll next_status = status >> 1;
          dp[idx + 1][next_status] += dp[idx][status];
          dp[idx + 1][next_status] %= MOD;
        } else {
          if((status & (1 << 1)) == 0 && j < m - 1) {
            // 가로로 채우기
            ll next_status = status | (1 << 0) | (1 << 1);
            next_status >>= 1;
            dp[idx + 1][next_status] += dp[idx][status];
            dp[idx + 1][next_status] %= MOD;
          }
          if(i < n - 1) { 
            // 세로로 채우기
            ll next_status = status | (1 << 0) | (1 << m);
            next_status >>= 1;
            dp[idx + 1][next_status] += dp[idx][status];
            dp[idx + 1][next_status] %= MOD;
          }
        }
      }
    }
  }

  cout << dp[n * m - 1][1] << '\n';

  
  return 0;
}