#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, s, d;
vector<map<ll, ll>> e;
vector<ll> dist, visited;
vector<vector<ll>> from;

bool init() {
  cin >> n >> m;
  if(n == 0 && s == 0) return false;
  cin >> s >> d;
  e.assign(n, map<ll, ll>());
  for(ll i = 0; i < m; i++) {
    ll u, v, c;
    cin >> u >> v >> c;
    e[u][v] = c;
  }
  return true;
}

void dijikstra(bool should_cut) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  
  dist.assign(n, INF);
  if(should_cut) {
    from.assign(n, vector<ll>());
  }
  dist[s] = 0;
  q.push({0, s});
  while(q.size()) {
    auto [d, now] = q.top();
    q.pop();
    if(d > dist[now]) continue;
    for(auto [next, cost]: e[now]) {
      if(dist[next] > dist[now] + cost) {
        dist[next] = dist[now] + cost;
        if(should_cut) {
          from[next].clear();
          from[next].push_back(now);
        }
        q.push({dist[next], next});
      } else if(dist[next] == dist[now] + cost) {
        if(should_cut) {
          from[next].push_back(now);
        }
      }
    }
  }

  if(!should_cut) return;

  queue<ll> tracking_q;
  visited.assign(n, 0);
  visited[d] = true;
  tracking_q.push(d);
  while(tracking_q.size()) {
    ll now = tracking_q.front();
    tracking_q.pop();
    for(ll next: from[now]) {
      e[next].erase(now);
      if(!visited[next]) {
        visited[next] = true;
        tracking_q.push(next);
      }
    }
  }
}

void solve() {
  dijikstra(true);
  dijikstra(false);
  if(dist[d] == INF) {
    cout << -1 << '\n';
  } else {
    cout << dist[d] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  while(true) {
    if(!init()) break;
    solve();
  }
  return 0;
}