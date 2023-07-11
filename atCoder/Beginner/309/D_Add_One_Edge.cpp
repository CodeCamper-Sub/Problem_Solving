#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n_1, n_2, n, m, a, b, source, sink;
vector<vector<ll>> e;

ll bfs(ll source) {
  vector<ll> dist(n + 1, INF);
  dist[source] = 0;
  queue<ll> q;
  q.push(source);
  ll result = 0;
  while(q.size()) {
    ll now = q.front();
    q.pop();
    for(ll next: e[now]) {
      if(dist[next] > dist[now] + 1) {
        dist[next] = dist[now] + 1;
        result = max(result, dist[next]);
        q.push({next});
      }
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n_1 >> n_2 >> m;
  n = n_1 + n_2;
  source = 1;
  sink = n_1 + n_2;
  e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  cout << bfs(source) + bfs(sink) + 1 << '\n';
  
  return 0;
}