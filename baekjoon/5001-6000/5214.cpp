#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, K, M;
vector<ll> dist, inQ;
vector<vector<ll>> e, h;
queue<ll> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K >> M;

  dist.assign(N + 1, INF);
  inQ.assign(N + 1, false);
  e.resize(N + 1);
  h.assign(M, vector<ll>(K));
  for(ll i = 0; i < M; i++) {
    for(ll j = 0; j < K; j++) {
      cin >> h[i][j];
      e[h[i][j]].push_back(i);
    }
  }

  dist[1] = 1;
  inQ[1] = true;
  q.push(1);
  while(q.size()) {
    ll now = q.front(); 
    q.pop();
    inQ[now] = false;
    for(ll tube: e[now]) {
      for(ll next: h[tube]) {
        if(dist[next] > dist[now] + 1) {
          dist[next] = dist[now] + 1;
          if(!inQ[next]) {
            inQ[next] = true;
            q.push(next);
          }
          if(dist[N] != INF) break;
        }
      }
      if(dist[N] != INF) break;
    }
    if(dist[N] != INF) break;
  }

  if(dist[N] == INF) {
    cout << -1 << '\n';
  } else {
    cout << dist[N] << '\n';
  }

  
  return 0;
}