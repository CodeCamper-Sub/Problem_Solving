//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
typedef long long ll;
using namespace std;

ll v, e, a, b, c, answer;
ll path[1010][1010];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> v >> e;
  for(ll i = 0; i <= v; i++) {
    for(ll j = 0; j <= v; j++) {
      path[i][j] = LONG_LONG_MAX;
    }
  }
  for(ll i = 1; i <= e; i++) {
    cin >> a >> b >> c;
    path[a][b] = min(path[a][b], c);
  }
  for(ll k = 1; k <= v; k++) {
    for(ll i = 1; i <= v; i++) {
      for(ll j = 1; j <= v; j++) {
        if(path[i][k] != LONG_LONG_MAX && path[k][j] != LONG_LONG_MAX) {
          path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
        }
      }
    }
  }
  answer = LONG_LONG_MAX;
  for(ll i = 1; i <= v; i++) {
    answer = min(answer, path[i][i]);
  }
  if(answer == LONG_LONG_MAX) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}

