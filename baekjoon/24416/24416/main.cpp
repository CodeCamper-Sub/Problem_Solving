//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll n;
ll dp[50];

void calc_dp() {
  dp[1] = 1;
  dp[2] = 1;
  for(ll i = 3; i <= 40; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  calc_dp();
  cin >> n;
  cout << dp[n] << ' ' << n-2 << '\n';
  
  return 0;
}

