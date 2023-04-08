#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, q, s, t, d;
vector<vector<ll>> dist;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  dist.assign(n + 1, vector<ll>(n + 1, INF));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> d;
      if(d == 1) dist[i][j] = 1;
    }
  }

  for(ll k = 0; k < n; k++) {
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  cin >> q;
  while(q--) {
    cin >> s >> t;
    s = (s - 1) % n;
    t = (t - 1) % n;
    if(dist[s][t] != INF) {
      cout << dist[s][t] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  
  return 0;
}