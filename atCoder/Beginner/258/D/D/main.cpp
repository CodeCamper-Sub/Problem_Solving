//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, x, a[200200], b[200200];
ll min_bi, clear_time[200200], dp[200200], answer;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  min_bi = LONG_LONG_MAX;
  answer = LONG_LONG_MAX;
  cin >> n >> x;
  for(ll i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    clear_time[i] = clear_time[i-1] + a[i] + b[i];
    min_bi = min(min_bi, b[i]);
    if(x - i >= 0) {
      dp[i] = clear_time[i] + min_bi * (x - i);
      answer = min(dp[i], answer);
    }
  }
  
  cout << answer << '\n';
  
  return 0;
}

