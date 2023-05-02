#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, source, sink, u, v, c, answer;
vector<ll> dist, backtracking_visited;
vector<vector<pair<ll, ll>>> e;
vector<vector<ll>> visited;
using Edge = pair<ll, ll>;
priority_queue<Edge, vector<Edge>, greater<Edge>> q;
queue<ll> backtracking_q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  dist.assign(n + 1, INF);
  visited.resize(n + 1);
  for(ll i = 0; i < m; i++) {
    cin >> u >> v >> c;
    e[u].push_back({v, -c});
  }
  
  cin >> source >> sink;
  dist[source] = 0;
  for(auto [next, cost]: e[source]) {
    dist[next] = cost;
    visited[next].push_back(source);
    q.push({cost, next});
  }

  while(q.size()) {
    auto [d, now] = q.top();
    q.pop();
    if(dist[now] < d) continue;
    for(auto [next, cost]: e[now]) {
      if(dist[next] > d + cost) {
        dist[next] = d + cost;
        visited[next].clear();
        visited[next].push_back(now);
        q.push({dist[next], next});
      } else if(dist[next] == d + cost) {
        visited[next].push_back(now);
      }
    }
  }

  backtracking_visited.assign(n, false);
  backtracking_q.push(sink);
  while(backtracking_q.size()) {
    ll now = backtracking_q.front();
    backtracking_q.pop();
    answer += visited[now].size();
    for(ll next: visited[now]) {
      if(!backtracking_visited[next]) {
        backtracking_visited[next] = true;
        backtracking_q.push(next);
      }
    }
  }

  cout << -dist[sink] << '\n';
  cout << answer << '\n';
  
  return 0;
}