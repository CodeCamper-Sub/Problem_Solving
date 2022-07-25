//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;

ll n, m, edges[110][110];
ll origin, destination, cost;
vector<ll> waypoints[110][110];

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for(ll i = 0; i <= n; i++) {
    for(ll j = 0; j <= n; j++) {
      edges[i][j] = LONG_LONG_MAX;
    }
  }
  
  for(ll i = 1; i <= m; i++) {
    cin >> origin >> destination >> cost;
    edges[origin][destination] = min(cost, edges[origin][destination]);
  }
  
  for(ll k = 1; k <= n; k++) {
    for(ll i = 1; i <= n; i++) {
      for(ll j = 1; j <= n; j++) {
        if(i == j) continue;
        if(edges[i][k] != LONG_LONG_MAX && edges[k][j] != LONG_LONG_MAX && edges[i][j] > edges[i][k] + edges[k][j]) {
          waypoints[i][j] = vector<ll>();
          for(ll t = 0; t < waypoints[i][k].size(); t++) {
            waypoints[i][j].push_back(waypoints[i][k][t]);
          }
          waypoints[i][j].push_back(k);
          for(ll t = 0; t < waypoints[k][j].size(); t++) {
            waypoints[i][j].push_back(waypoints[k][j][t]);
          }
          edges[i][j] = edges[i][k] + edges[k][j];
        }
      }
    }
  }
  
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(edges[i][j] != LONG_LONG_MAX) {
        cout << edges[i][j] << ' ';
      } else {
        cout << 0 << ' ';
      }
    }
    cout << '\n';
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(edges[i][j] == LONG_LONG_MAX) {
        cout << 0 << '\n';
      } else {
        cout << waypoints[i][j].size() + 2 << ' ';
        cout << i << ' ';
        for(ll t = 0; t < waypoints[i][j].size(); t++) {
          cout << waypoints[i][j][t] << ' ';
        }
        cout << j << '\n';
      }
    }
  }
  
  return 0;
}

