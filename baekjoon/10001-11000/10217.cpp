#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, k;
vector<vector<tuple<ll, ll, ll>>> e;
vector<vector<ll>> visited;

void init() {
  cin >> n >> m >> k;
  for(auto& v: e) v.clear();
  e.clear();
  e.assign(n + 1, vector<tuple<ll, ll, ll>>());
  for(auto& v: visited) v.clear();
  visited.clear();
  visited.assign(n + 1, vector<ll>(m + 1, INF));
  for(ll i = 0; i < k; i++) {
    ll u, v, c, d;
    cin >> u >> v >> c >> d;
    e[u].push_back({v, c, d});
  }
}

void solve() {
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;
  visited[1][0] = 0;
  q.push({0, 0, 1});
  while(q.size()) {
    auto [d, c, now] = q.top();
    q.pop();
    if(d > visited[now][c]) continue;
    if(now == n) {
      cout << d << '\n';
      return;
    }
    for(auto [next, cost, dist]: e[now]) {
      if(c + cost > m) continue;
      if(visited[next][c + cost] > visited[now][c] + dist) {
        for(ll i = c + cost; i <= m; i++) visited[next][i] = min(visited[next][i], visited[now][c] + dist);
        q.push({visited[next][c + cost], c + cost, next});
      }
    }
  }
  cout << "Poor KCM\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}