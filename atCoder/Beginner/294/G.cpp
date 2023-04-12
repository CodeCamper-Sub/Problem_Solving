#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, slimit, u, v, w, root, id, q;
vector<ll> level, dist, in, out;
vector<vector<ll>> sparse;
vector<vector<pair<ll, ll>>> e;
vector<tuple<ll, ll, ll>> whole_e;

void dfs(ll now, ll parent) {
  in[now] = ++id;
  for(auto [next, w]: e[now]) {
    if(next != parent) {
      level[next] = level[now] + 1;
      dist[next] = dist[now] + w;
      dfs(next, now);
    }
  }
  out[now] = id;
}

ll set_level(ll a, ll to_level) {
  ll delta = level[a] - to_level;
  for(ll i = slimit - 1; i >= 0; i--) {
    if(delta >= (1ll << i)) {
      delta -= (1ll << i);
      a = sparse[i][a];
    }
  }
  return a;
}

ll lca(ll a, ll b) {
  a = set_level(a, min(level[a], level[b]));
  b = set_level(b, min(level[a], level[b]));

  if(a == b) return a;

  for(ll i = slimit - 1; i >= 0; i--) {
    if(sparse[i][a] != sparse[i][b]) {
      a = sparse[i][a];
      b = sparse[i][b];
    }
  }

  return sparse[0][a];
}

struct SegTree {
  vector<ll> tree, dist, lazy;
  ll root, start, end;
  SegTree(vector<ll> _dist) {
    dist.resize(_dist.size());
    for(ll i = 1; i <= N; i++) {
      dist[in[i]] = _dist[i];
    }
    tree.resize(dist.size() * 4);
    lazy.assign(dist.size() * 4, 0);
    root = 1;
    start = 1;
    end = dist.size() - 1;
    build_tree(root, start, end);
  }

  ll query(ll target) {
    return query(root, start, end, target);
  }

  void update(ll left, ll right, ll delta) {
    update(root, start, end, left, right, delta);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = dist[start];
    } else {
      ll mid = (start + end) >> 1;
      return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
    }
  }

  void propagate_lazy(ll node, ll start, ll end) {
    if(lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  ll update(ll node, ll start, ll end, ll left, ll right, ll delta) {
    propagate_lazy(node, start, end);
    if(right < start || end < left) {
      return tree[node];
    } else if(left <= start && end <= right) {
      lazy[node] += delta;
      propagate_lazy(node, start, end);
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, left, right, delta) + update(node * 2 + 1, mid + 1, end, left, right, delta);
    }
  }

  ll query(ll node, ll start, ll end, ll target) {
    propagate_lazy(node, start, end);
    if(target < start || end < target) {
      return -INF;
    } else if(start == end) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return max(query(node * 2, start, mid, target), query(node * 2 + 1, mid + 1, end, target));
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  slimit = ceil(log2(N)) + 1;
  sparse.assign(slimit, vector<ll>(N + 1));
  level.resize(N + 1);
  in.resize(N + 1);
  out.resize(N + 1);
  dist.resize(N + 1);
  e.resize(N + 1);
  for(ll i = 0; i < N - 1; i++) {
    cin >> u >> v >> w;
    whole_e.push_back({u, v, w});
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }

  root = 1;
  level[root] = 0;
  dist[root] = 0;
  dfs(root, -1);
  
  sparse[0][root] = root;
  for(auto& [u, v, w]: whole_e) {
    if(level[u] < level[v]) swap(u, v);
    sparse[0][u] = v;
  }

  for(ll i = 1; i < slimit; i++) {
    for(ll j = 1; j <= N; j++) {
      sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
    }
  }

  cin >> q;
  SegTree seg(dist);
  while(q--) {
    ll c;
    cin >> c;
    if(c == 1) {
      ll i, nw;
      cin >> i >> nw;
      auto& [u, v, w] = whole_e[i - 1];
      ll delta = nw - w;
      w = nw;
      seg.update(in[u], out[u], delta);
    } else {
      cin >> u >> v;
      cout << seg.query(in[u]) + seg.query(in[v]) - 2 * seg.query(in[lca(u, v)]) << '\n';
    }
  }
  
  return 0;
}