//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, x[220], y[220], p[220];
ll dist[220][220], answer, max_s;

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  
  for(ll i = 1; i <= n; i++){
    cin >> x[i] >> y[i] >> p[i];
  }
  
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      dist[i][j] = LONG_LONG_MAX;
    }
  }
  
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      ll cost = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      if(cost % p[i] == 0) {
        dist[i][j] = cost / p[i];
      } else {
        dist[i][j] = (cost / p[i]) + 1;
      }
    }
  }
  
  for(ll k = 1; k <= n; k++) {
    for(ll i = 1; i <= n; i++) {
      for(ll j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
      }
    }
  }
  
  answer = LONG_LONG_MAX;
  for(ll i = 1; i <= n; i++) {
    max_s = LONG_LONG_MIN;
    for(ll j = 1; j <= n; j++) {
      max_s = max(max_s, dist[i][j]);
    }
    answer = min(answer, max_s);
  }
  cout << answer << '\n';
  
  return 0;
}

