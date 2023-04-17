#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, u, v, c;
vector<vector<pair<ll, ll>>> e;
vector<ll> dist_a;
vector<vector<ll>> dist_b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  e.resize(n + 1);
  dist_a.assign(n + 1, INF);
  dist_b.assign(n + 1, vector<ll>(2, INF));
  for (ll i = 0; i < m; i++) {
    cin >> u >> v >> c;
    e[u].push_back({v, c * 2});
    e[v].push_back({u, c * 2});
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  dist_a[1] = 0;
  q.push({0, 1});
  while (q.size()) {
    auto [dist, now] = q.top();
    q.pop();
    if(dist > dist_a[now]) continue;
    for (auto [next, cost] : e[now]) {
      if (dist_a[next] > dist + cost) {
        dist_a[next] = dist + cost;
        q.push({dist + cost, next});
      }
    }
  }

  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>,
                 greater<tuple<ll, ll, ll>>>
      q_b;
  dist_b[1][0] = 0;
  q_b.push({0, 1, 0});
  while (q_b.size()) {
    auto [dist, now, status] = q_b.top();
    q_b.pop();
    if(dist > dist_b[now][status]) continue;
    for (auto [next, cost] : e[now]) {
      ll next_status = 1 - status;
      ll next_dist = dist;
      if (status == 0) {
        next_dist += cost / 2;
      } else {
        next_dist += cost * 2;
      }
      if (dist_b[next][next_status] > next_dist) {
        dist_b[next][next_status] = next_dist;
        q_b.push({next_dist, next, next_status});
      }
    }
  }

  ll answer = 0;
  for (ll i = 2; i <= n; i++) {
    if (dist_a[i] < min(dist_b[i][0], dist_b[i][1]))
      answer++;
  }

  cout << answer << '\n';

  return 0;
}