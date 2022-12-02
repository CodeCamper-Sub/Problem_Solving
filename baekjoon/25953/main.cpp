#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, t, m, s, e, a, b, w;
ll dist[10100][1010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> t >> m;
  cin >> s >> e;
  for(ll i = 0; i < n; i++) for(ll j = 0; j <= t; j++) {
    if(i == s) {
      dist[i][j] = 0;
    } else {
      dist[i][j] = INF;
    }
  }

  for(ll i = 1; i <= t; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> a >> b >> w;
      if(dist[a][i-1] != INF) {
        dist[b][i] = min(dist[b][i], min(dist[b][i-1], dist[a][i-1] + w));
      }
      if(dist[b][i-1] != INF) {
        dist[a][i] = min(dist[a][i], min(dist[a][i-1], dist[b][i-1] + w));
      }
    }
    for(ll j = 0; j < n; j++) {
      dist[j][i] = min(dist[j][i], dist[j][i-1]);
    }
  }

  if(dist[e][t] == INF) {
    cout << -1;
  } else {
    cout << dist[e][t];
  }

  return 0;
}