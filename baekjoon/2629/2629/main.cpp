//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n, m, w;
bool dp[40][20000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  dp[0][0] = true;
  for(ll i = 1; i <= n; i++) {
    cin >> w;
    for(ll k = 0; k <= 15000; k++) {
      if(dp[i-1][k]) {
        if(k + w <= 15000) {
          dp[i][k+w] = true;
        }
        if(k - w >= 0) {
          dp[i][k-w] = true;
        }
        if(w - k >= 0) {
          dp[i][w-k] = true;
        }
        dp[i][k] = true;
      }
    }
  }
  
  cin >> m;
  for(ll i = 1; i <= m; i++) {
    cin >> w;
    if(dp[n][w]) {
      cout << "Y ";
    } else {
      cout << "N ";
    }
  }
  cout << '\n';
  
  return 0;
}

