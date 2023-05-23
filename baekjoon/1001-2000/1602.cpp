#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, q;
vector<vector<ll>> dist;
vector<vector<pair<ll, ll>>> e;
vector<ll> monkey;

struct PairHash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    // 각 구성 요소에 대한 해시 값을 조합
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
    return h1 ^ h2; // 예시로 XOR 연산을 사용하여 조합
  }
};

void dijkstra(ll from) {
  unordered_map<pair<ll, ll>, ll, PairHash> visited;
  vector<ll> min_dists;
  priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> q;
  min_dists.assign(n + 1, INF);
  visited[{from, monkey[from]}] = monkey[from];
  min_dists[from] = monkey[from];
  q.push({visited[{from, monkey[from]}], from, monkey[from]});
  while (q.size()) {
    auto [d, now, m] = q.top();
    q.pop();
    if (d > visited[{now, m}])
      continue;
    for (auto [cost, next] : e[now]) {
      if (monkey[next] > m) {
        if (visited.count({next, monkey[next]}) == 0 ||
            visited[{next, monkey[next]}] >
                visited[{now, m}] - m + monkey[next] + cost) {
          visited[{next, monkey[next]}] =
              visited[{now, m}] - m + monkey[next] + cost;
          min_dists[next] = min(min_dists[next], visited[{next, monkey[next]}]);
          q.push({visited[{next, monkey[next]}], next, monkey[next]});
        }
      } else {
        if (visited.count({next, m}) == 0 ||
            visited[{next, m}] > visited[{now, m}] + cost) {
          visited[{next, m}] = visited[{now, m}] + cost;
          min_dists[next] = min(min_dists[next], visited[{next, m}]);
          q.push({visited[{next, m}], next, m});
        }
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    dist[from][i] = min_dists[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> q;

  monkey.resize(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> monkey[i];
  }

  e.resize(n + 1);
  for (ll i = 0; i < m; i++) {
    ll a, b, d;
    cin >> a >> b >> d;
    e[a].push_back({d, b});
    e[b].push_back({d, a});
  }

  dist.assign(n + 1, vector<ll>(n + 1, INF));
  for (ll i = 1; i <= n; i++) {
    dijkstra(i);
  }

  while (q--) {
    ll s, t;
    cin >> s >> t;
    if (dist[s][t] != INF) {
      cout << dist[s][t] << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}