#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 2020
typedef long long ll;
using namespace std;

ll n, u, v, c;
pair<ll, ll> ignored; // first 노드와 second노드를 연결하는 Edge를 무시함
vector<pair<ll ,ll>> e[MAX];

void dfs(ll now, ll dist[], ll& fartest_node, ll& fartest_dist, ll visited[]) {
  if(dist[now] > fartest_dist) {
    fartest_dist = dist[now];
    fartest_node = now;
  }
  for(auto [next, cost]: e[now]) {
    if(ignored == make_pair(now, next) || ignored == make_pair(next, now)) continue;
    if(!visited[next]) {
      visited[next] = true;
      dist[next] = dist[now] + cost;
      dfs(next, dist, fartest_node, fartest_dist, visited);
    }
  }
}

ll get_diameter(ll node) {
  ll dist[MAX], visited[MAX], fartest_node, fartest_dist;

  fill(dist, dist + MAX, INF);
  fill(visited, visited + MAX, false);
  dist[node] = 0;
  fartest_dist = -INF;
  visited[node] = true;
  dfs(node, dist, fartest_node, fartest_dist, visited);

  fill(dist, dist + MAX, INF);
  fill(visited, visited + MAX, false);
  dist[fartest_node] = 0;
  fartest_dist = -INF;
  visited[fartest_node] = true;
  dfs(fartest_node, dist, fartest_node, fartest_dist, visited);
  return fartest_dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n - 1; i++) {
    cin >> u >> v >> c;
    e[u].push_back({v, c});
    e[v].push_back({u, c});
  }

  ll answer = -INF;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < e[i].size(); j++) {
      ignored = {i, e[i][j].first};
      answer = max(answer, get_diameter(i) + get_diameter(e[i][j].first) + e[i][j].second);
    }
  }

  cout << answer << '\n';
  
  return 0;
}