#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m, a, b, t;
vector<ll> dist;
vector<vector<pair<ll, ll>>> e;
vector<pair<ll, ll>> all_edges;

struct Compare {
  bool operator()(const ll& a, const ll& b) {
    return dist[a] > dist[b];
  }
};

ll dijikstra(ll a, ll b) {
  dist.assign(n + 1, INF);
  vector<ll> tracking;
  vector<bool> inQ(n + 1, false);
  if(a == -1 && b == -1) {
    tracking.resize(n + 1, -1);
  }
  dist[1] = 0;
  priority_queue<ll, vector<ll>, Compare> q;
  q.push(1);
  inQ[1] = true;
  while(q.size()) {
    ll now = q.top();
    q.pop();
    inQ[now] = false;
    if(now == n) break;
    for(auto [next, cost]: e[now]) {
      if((now == a && next == b) || (now == b && next == a)) continue;
      if(dist[next] > dist[now] + cost) {
        if(a == -1 && b == -1) tracking[next] = now;
        dist[next] = dist[now] + cost;
        if(!inQ[next]) {
          q.push(next);
          inQ[next] = true;
        }
      }
    }
  }

  if(a == -1 && b == -1 && dist[n] != INF) {
    ll now = n;
    while(now != 1) {
      all_edges.push_back({now, tracking[now]});
      now = tracking[now];
    }
  }

  return dist[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    cin >> a >> b >> t;
    e[a].push_back({b, t});
    e[b].push_back({a, t});
  }

  ll mini = dijikstra(-1, -1);
  if(mini == INF) {
    cout << 0 << '\n';
    return 0;
  }
  ll answer = 0;
  for(auto [a, b]: all_edges) {
    ll result = dijikstra(a, b);
    if(result == INF) {
      cout << -1 << '\n';
      return 0;
    }
    answer = max(answer, result - mini);
  }

  cout << answer << '\n';

  return 0;
}