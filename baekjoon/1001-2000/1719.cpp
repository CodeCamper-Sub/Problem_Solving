#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<vector<ll>> dist;
vector<vector<ll>> transmission;
ll n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  dist.assign(n + 1, vector<ll>(n + 1, INF));
  transmission.assign(n + 1, vector<ll>(n + 1, -1));
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    if(dist[u][v] > c) {
      dist[u][v] = c;
      dist[v][u] = c;
      transmission[u][v] = v;
      transmission[v][u] = u;
    }
  }

  for(ll k = 1; k <= n; k++) {
    for(ll i = 1; i <= n; i++) {
      for(ll j = 1; j <= n; j++) {
        if(dist[i][k] == INF || dist[k][j] == INF || i == j) continue;
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          transmission[i][j] = transmission[i][k];
        }
      }
    }
  }

  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(transmission[i][j] == -1) {
        cout << '-' << ' ';
      } else {
        cout << transmission[i][j] << ' ';
      }
    }
    cout << '\n';
  }
  
  return 0;
}