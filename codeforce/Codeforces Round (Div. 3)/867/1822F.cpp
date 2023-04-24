#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, c;
vector<ll> level;
vector<vector<ll>> e;
vector<vector<ll>> sparse;

void init() {
  cin >> n >> k >> c;
  e.assign(n + 1, vector<ll>());
  sparse.assign(ceil(log2(n)), vector<ll>(n + 1));
  level.assign(n + 1, -1);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
}

void dfs(ll now) {
  for(ll next: e[now]) {
    if(level[next] == -1) {
      level[next] = level[now] + 1;
      dfs(next);
    }
  }
}

ll set_level(ll a, ll to_level) {
  ll delta = level[a] - to_level;
  for(ll i = ceil(log2(n)) - 1; i >= 0; i--) {
    if(delta >= (1ll << i)) {
      delta -= (1ll << i);
      a = sparse[i][a];
    }
  }
  return a;
}

ll lca(ll a, ll b) {
  ll same_level = min(level[a], level[b]);
  a = set_level(a, same_level);
  b = set_level(b, same_level);
  if(a == b) return a;
  for(ll i = ceil(log2(n)) - 1; i >= 0; i--) {
    if(sparse[i][a] != sparse[i][b]) {
      a = sparse[i][a];
      b = sparse[i][b];
    }
  }
  return sparse[0][a];
}

void solve() {
  level[1] = 0;
  dfs(1);

  sparse[0][1] = 1;
  for(ll i = 1; i <= n; i++) {
    for(ll j: e[i]) {
      if(level[i] > level[j]) {
        sparse[0][i] = j;
        break;
      }
    }
  }

  for(ll i = 1; i < ceil(log2(n)); i++) {
    for(ll j = 1; j <= n; j++) {
      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  return;
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