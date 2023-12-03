#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll m, n, k, source, sink;
vector<map<ll, ll>> ind, outd, dist;
vector<map<ll, map<ll, ll>>> edge, forbidden;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n >> k;
  cin >> source >> sink;
  
  if(source == sink) {
    cout << 0 << '\n';
    return 0;
  }

  ind.resize(n);
  outd.resize(n);
  edge.resize(n);
  forbidden.resize(n);
  dist.resize(n);
  for(ll i = 0; i < m; i++) {
    ll x, y, c;
    cin >> x >> y >> c;
    ind[y][x] = c;
    outd[x][y] = c;
  }
  for(ll i = 0; i < k; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    forbidden[x][y][z]++;
  }

  for(ll now = 0; now < n; now++) {
    for(auto [prev, _]: ind[now]) {
      for(auto [next, c]: outd[now]) {
        if(forbidden[prev].count(now) && forbidden[prev][now].count(next)) continue;
        
        edge[now][prev][next] = c;
      }
    }
  }

  for(ll now = 0; now < n; now++) {
    for(auto [prev, _]: ind[now]) {
      dist[now][prev] = INF;
    }
  }

  min_heap<tuple<ll, ll, ll>> q; // {dist, prev, now}
  for(auto [next, c]: outd[source]) {
    dist[next][source] = c;
    q.push({c, source, next});
  }
  while(q.size()) {
    auto [now_d, prev, now] = q.top();
    q.pop();
    if(now_d > dist[now][prev] || !edge[now].count(prev)) continue;
    for(auto [next, c]: edge[now][prev]) {
      if(dist[next][now] > now_d + c) {
        dist[next][now] = now_d + c;
        q.push({dist[next][now], now, next});
      }
    }
  }

  ll answer = INF;
  for(auto [_, d]: dist[sink]) {
    answer = min(answer, d);
  }

  if(answer == INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }

  
  return 0;
}