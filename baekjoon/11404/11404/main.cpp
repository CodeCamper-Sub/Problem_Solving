//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll n, m, a, b, c;
ll path[200][200];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  
  for(ll i = 0; i <= n; i++) {
    for(ll j = 0; j <= n; j++) {
      path[i][j] = LONG_LONG_MAX;
      if(i == j) path[i][j] = 0;
    }
  }
  for(ll i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    path[a][b] = min(path[a][b], c);
  }
  for(ll k = 1; k <= n; k++) {
    for(ll i = 1; i <= n; i++) {
      for(ll j = 1; j <= n; j++) {
        if(path[i][k] != LONG_LONG_MAX && path[k][j] != LONG_LONG_MAX) {
          path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
        }
      }
    }
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(path[i][j] != LONG_LONG_MAX) {
        cout << path[i][j] << ' ';
      } else {
        cout << 0 << ' ';
      }
    }
    cout << '\n';
  }
  
  
  return 0;
}

