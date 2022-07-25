//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, k, v;
ll dp[2][10010];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  cin >> v;
  for(ll i = 0; i <= k; i++) {
    if(i % v == 0) {
      dp[0][i] = 1;
    }
  }
  for(ll i = 2; i <= n; i++) {
    cin >> v;
    for(ll j = 0; j <= k; j++) {
      for(ll k = 0; j - v * k >= 0; k++) {
        dp[1][j] += dp[0][j-v*k];
      }
    }
    for(ll j = 0; j <= k; j++) {
      dp[0][j] = dp[1][j];
      dp[1][j] = 0;
    }
  }
  cout << dp[0][k] << '\n';
  
  return 0;
}

