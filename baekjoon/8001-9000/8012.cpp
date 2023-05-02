#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, answer, v, pre_v;
vector<vector<ll>> e, sparse;
vector<ll> level;

void dfs(ll now, ll parent) {
  sparse[0][now] = parent;
  for(ll next: e[now]) {
    if(next == parent) continue;
    level[next] = level[now] + 1;
    dfs(next, now);
  }
}

ll set_level(ll now, ll to_level) {
  ll delta = level[now] - to_level;
  if(delta <= 0) return now;
  for(ll i = 62; i >= 0; i--) {
    if(delta >= (1ll << i)) {
      delta -= (1ll << i);
      now = sparse[i][now];
    }
  }
  return now;
}

ll lca(ll a, ll b) {
  a = set_level(a, min(level[a], level[b]));
  b = set_level(b, min(level[a], level[b]));
  if(a == b) return a;
  for(ll i = 62; i >= 0; i--) {
    if(sparse[i][a] != sparse[i][b]) {
      a = sparse[i][a];
      b = sparse[i][b];
    }
  }
  return sparse[0][a];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.resize(n + 1);
  sparse.assign(63, vector<ll>(n + 1));
  level.resize(n + 1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }

  level[1] = 0;
  dfs(1, 1);
  for(ll i = 1; i <= 62; i++) {
    for(ll j = 1; j <= n; j++) {
      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  cin >> m;
  answer = 0;
  for(ll i = 0; i < m; i++) {
    cin >> v;
    if(i == 0) {
      answer += level[v];
    } else {
      answer += level[v] + level[pre_v] - 2 * level[lca(v, pre_v)];
    }
    pre_v = v;
  }

  cout << answer << '\n';
  
  return 0;
}