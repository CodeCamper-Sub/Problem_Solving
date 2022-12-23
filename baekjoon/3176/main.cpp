#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll get_root(ll ind[], ll N) {
  for(ll i = 1; i <= N; i++) {
    if(ind[i] > 1) return i;
  }
}

void dfs(ll now, vector<pair<ll, ll>> e[], ll parent[], ll depth[], ll weight_to_parent[]) {
  for(ll i = 0; i < e[now].size(); i++) {
    ll next = e[now][i].first;
    ll weight = e[now][i].second;
    if(depth[next] == -1) {
      depth[next] = depth[now] + 1;
      parent[next] = now;
      weight_to_parent[next] = weight;
      dfs(next, e, parent, depth, weight_to_parent);
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

void build_minimum_sparse(ll minimum_sparse[][100100], ll parent_sparse[][100100],ll weight_to_parent[], ll N) {
  for(ll i = 1; i <= N; i++) {
    minimum_sparse[0][i] = weight_to_parent[i];
  }
  for(ll k = 1; k < 20; k++) {
    for(ll i = 1; i <= N; i++) {
      minimum_sparse[k][i] = min(minimum_sparse[k-1][i], minimum_sparse[k-1][parent_sparse[k-1][i]]);
    }
  }
}

void build_maximum_sparse(ll maximum_sparse[][100100], ll parent_sparse[][100100],ll weight_to_parent[], ll N) {
  for(ll i = 1; i <= N; i++) {
    maximum_sparse[0][i] = weight_to_parent[i];
  }
  for(ll k = 1; k < 20; k++) {
    for(ll i = 1; i <= N; i++) {
      maximum_sparse[k][i] = max(maximum_sparse[k-1][i], maximum_sparse[k-1][parent_sparse[k-1][i]]);
    }
  }
}

ll change_depth(ll a, ll to_depth, ll depth[], ll sparse[][100100]) {
  ll interval = depth[a] - to_depth;
  for(ll k = 19; k >= 0; k--) {
    if(interval >= (1 << k)) {
      a = sparse[k][a];
      interval = depth[a] - to_depth;
    }
    if(interval <= 0) break;
  }
  return a;
}

ll lca(ll a, ll b, ll depth[], ll sparse[][100100]) {
  a = change_depth(a, min(depth[a], depth[b]), depth, sparse);
  b = change_depth(b, min(depth[a], depth[b]), depth, sparse);
  if(a == b) return a;
  while(sparse[0][a] != sparse[0][b]) {
    for(ll k = 1; k < 20; k++) {
      if(sparse[k][a] == sparse[k][b]) {
        a = sparse[k-1][a];
        b = sparse[k-1][b];
        break;
      }
    }
  }
  return sparse[0][a];
}

ll get_min_path(ll a, ll parent, ll depth[], ll minimum_sparse[][100100], ll parent_sparse[][100100]) {
  ll interval = depth[a] - depth[parent];
  ll minimum = INF;
  for(ll k = 19; k >= 0; k--) {
    if(interval >= (1 << k)) {
      minimum = min(minimum, minimum_sparse[k][a]);
      a = parent_sparse[k][a];
      interval = depth[a] - depth[parent];
    }
    if(interval <= 0) break;
  }
  return minimum;
}

ll get_max_path(ll a, ll parent, ll depth[], ll maximum_sparse[][100100], ll parent_sparse[][100100]) {
  ll interval = depth[a] - depth[parent];
  ll maximum = -INF;
  for(ll k = 19; k >= 0; k--) {
    if(interval >= (1 << k)) {
      maximum = max(maximum, maximum_sparse[k][a]);
      a = parent_sparse[k][a];
      interval = depth[a] - depth[parent];
    }
    if(interval <= 0) break;
  }
  return maximum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  vector<pair<ll, ll>> e[100100]; // <destination, weight>
  ll ind[100100];

  cin >> N;
  for(ll i = 0; i < N-1; i++) {
    ll A, B, C;
    cin >> A >> B >> C;
    ind[A]++;
    ind[B]++;
    e[A].push_back({B, C});
    e[B].push_back({A, C});
  }

  ll root = get_root(ind, N);
  ll depth[100100];
  ll parent[100100];
  ll weight_to_parent[100100];
  for(ll i = 0; i <= N; i++) {
    depth[i] = -1;
  }
  depth[root] = 1;
  parent[root] = -1;
  weight_to_parent[root] = INF;
  dfs(root, e, parent, depth, weight_to_parent);

  ll parent_sparse[20][100100];
  build_parent_sparse(parent_sparse, parent, N);

  ll minimum_sparse[20][100100];
  weight_to_parent[root] = INF;
  build_minimum_sparse(minimum_sparse, parent_sparse, weight_to_parent, N);

  ll maximum_sparse[20][100100];
  weight_to_parent[root] = -INF;
  build_maximum_sparse(maximum_sparse, parent_sparse, weight_to_parent, N);

  ll K;
  cin >> K;
  for(ll i = 0; i < K; i++) {
    ll A, B;
    cin >> A >> B;
    ll parent = lca(A, B, depth, parent_sparse);
    ll minimum = min(get_min_path(A, parent, depth, minimum_sparse, parent_sparse), get_min_path(B, parent, depth, minimum_sparse, parent_sparse));
    ll maximum = max(get_max_path(A, parent, depth, maximum_sparse, parent_sparse), get_max_path(B, parent, depth, maximum_sparse, parent_sparse));
    cout << minimum << ' ' << maximum << '\n';
  }



  return 0;
}