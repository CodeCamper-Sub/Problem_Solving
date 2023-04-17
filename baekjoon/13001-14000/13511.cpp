#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

void dfs(ll now, vector<pair<ll, ll>> e[], ll depth[], ll parent[], ll weight_to_parent[]) {
  for(ll i = 0; i < e[now].size(); i++) {
    ll next = e[now][i].first;
    ll cost = e[now][i].second;
    if(depth[next] == -1) {
      depth[next] = depth[now] + 1;
      parent[next] = now;
      weight_to_parent[next] = cost;
      dfs(next, e, depth, parent, weight_to_parent);
    }
  }
}

void build_parent_sparse(ll sparse[][100100], ll parent[], ll N) {
  for(ll i = 1; i <= N; i++) {
    sparse[0][i] = parent[i];
  }
  for(ll k = 1; k < 20; k++) {
    for(ll i = 1; i <= N; i++) {
      if(sparse[k-1][i] >= 0) {
        sparse[k][i] = sparse[k-1][sparse[k-1][i]];
      } else {
        sparse[k][i] = -1;
      }
    }
  }
}

void build_cost_sparse(ll cost_sparse[][100100], ll parent_sparse[][100100], ll weight_to_parent[], ll N) {
  for(ll i = 1; i <= N; i++) {
    cost_sparse[0][i] = weight_to_parent[i];
  }
  for(ll k = 1; k < 20; k++) {
    for(ll i = 1; i <= N; i++) {
      cost_sparse[k][i] = cost_sparse[k-1][i] + cost_sparse[k-1][parent_sparse[k-1][i]];
    }
  }
}

ll change_depth(ll a, ll to_depth, ll depth[], ll parent_sparse[][100100]) {
  ll interval = depth[a] - to_depth;
  for(ll k = 19; k >= 0; k--) {
    if(interval >= (1<<k)) {
      a = parent_sparse[k][a];
      interval = depth[a] - to_depth;
    }
    if(interval <= 0) break;
  }
  return a;
}

ll lca(ll a, ll b, ll depth[], ll parent_sparse[][100100]) {
  a = change_depth(a, min(depth[a], depth[b]), depth, parent_sparse);
  b = change_depth(b, min(depth[a], depth[b]), depth, parent_sparse);
  if(a == b) return a;
  while(parent_sparse[0][a] != parent_sparse[0][b]) {
    for(ll k = 1; k < 20; k++) {
      if(parent_sparse[k][a] == parent_sparse[k][b]) {
        a = parent_sparse[k-1][a];
        b = parent_sparse[k-1][b];
        break;
      }
    }
  }
  return parent_sparse[0][a];
}

ll get_cost(ll a, ll ancestor, ll depth[], ll parent_sparse[][100100], ll cost_sparse[][100100]) {
  ll interval = depth[a] - depth[ancestor];
  ll cost_sum = 0;
  for(ll k = 19; k >= 0; k--) {
    if(interval >= (1 << k)) {
      cost_sum += cost_sparse[k][a];
      a = parent_sparse[k][a];
      interval = depth[a] - depth[ancestor];
    }
    if(interval <= 0) break;
  }
  return cost_sum;
}

ll get_node(ll a, ll to_depth, ll depth[], ll parent_sparse[][100100], ll cost_sparse[][100100]) {
  ll interval = depth[a] - to_depth;
  for(ll k = 19; k >= 0; k--) {
    if(interval >= (1 << k)) {
      a = parent_sparse[k][a];
      interval = depth[a] - to_depth;
    }
    if(interval <= 0) break;
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  vector<pair<ll, ll>> e[100100]; // <Destination, Cost>
  ll ind[100100];
  cin >> N;
  for(ll i = 1; i <= N; i++) ind[i] = 0;
  for(ll i = 0; i < N-1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    ind[u]++;
    ind[v]++;
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }

  ll root;
  for(ll i = 1; i <= N; i++) {
    if(ind[i] > 1) {
      root = i;
      break;
    }
  }

  ll depth[100100], parent[100100], weight_to_parent[100100];
  for(ll i = 1; i <= N; i++) {
    depth[i] = -1;
  }
  depth[root] = 0;
  parent[root] = -1;
  weight_to_parent[root] = INF;
  dfs(root, e, depth, parent, weight_to_parent);

  ll parent_sparse[20][100100];
  build_parent_sparse(parent_sparse, parent, N);

  ll cost_sparse[20][100100];
  build_cost_sparse(cost_sparse, parent_sparse, weight_to_parent, N);

  ll M;
  cin >> M;
  for(ll i = 0; i < M; i++) {
    ll c, u, v, k;
    cin >> c >> u >> v;
    ll ancestor = lca(u, v, depth, parent_sparse);
    if(c == 1) {
      cout << get_cost(u, ancestor, depth, parent_sparse, cost_sparse) + get_cost(v, ancestor, depth, parent_sparse, cost_sparse) << '\n';
    } else {
      cin >> k;
      if(depth[u] - depth[ancestor] >= k) {
        cout << get_node(u, depth[u] - k + 1, depth, parent_sparse, cost_sparse) << '\n';
      } else {
        ll to_depth = depth[v] - ((depth[u] - depth[ancestor]) + (depth[v] - depth[ancestor]) - k + 1);
        cout << get_node(v, to_depth, depth, parent_sparse, cost_sparse) << '\n';
      }
    }
  }
  return 0;
}