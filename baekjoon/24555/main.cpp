#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 100100
typedef long long ll;
using namespace std;

ll n, dp[100100], closet_index;
set<ll> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  dp[1] = 1;
  closet_index = 1;
  for(ll i = 2; i <= n; i++) {
    dp[i] = INF;
    for(ll j = 2; j * j <= i; j++) {
      if(i % j) continue;
      dp[i] = min(dp[i], dp[j] + dp[i / j]);
    }
    for(ll j = 10; j <= 100000; j *= 10) {
      if(i / j == 0) {
        break;
      } else if(i % j < j / 10) {
        continue;
      }
      dp[i] = min(dp[i], dp[i / j] + dp[i % j]);
    }
    for(ll j = 1; j <= i / 2; j++) {
      if(dp[i] > dp[i - j] + dp[j]) {
        dp[i] = dp[i - j] + dp[j];
      }
    }
  }

  cout << dp[n] << '\n';

  
  return 0;
}