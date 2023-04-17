#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree, lazy;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    lazy.resize(n * 4);
    root = 1;
    start = 1;
    end = n;
    build_tree(root, start, end);
  }
  
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  void update(ll left, ll right, ll delta) {
    update(root, start, end, left, right, delta);
  }

  private:
  void propagate_lazy(ll node, ll start, ll end) {
    if(lazy[node] == 0) return;
    if(lazy[node] == 1) {
      tree[node] = (end - start + 1);
    } else {
      tree[node] = 0;
    }
    if(start != end) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    propagate_lazy(node, start, end);
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll left, ll right, ll delta) {
    propagate_lazy(node, start, end);
    if(right < start || end < left) {
      return tree[node];
    } else if(left <= start && end <= right) {
      lazy[node] = delta;
      propagate_lazy(node, start, end);
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = update(node * 2, start, mid, left, right, delta) + update(node * 2 + 1, mid + 1, end, left, right, delta);
    }
  }

  ll build_tree(ll node, ll start, ll end) {
    lazy[node] = 0;
    if(start == end) {
      return tree[node] = 1;
    } else {
      ll mid = start + end >> 1;
      return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
    }
  }
};

ll n, m, cnt;

vector<ll> in, out;
vector<vector<ll>> e;

void dfs(ll now) {
  in[now] = ++cnt;
  for(ll next: e[now]) {
    dfs(next);
  }
  out[now] = cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  in.resize(n + 1);
  out.resize(n + 1);
  e.resize(n + 1);
  
  for(ll i = 1; i <= n; i++) {
    ll u;
    cin >> u;
    if(u > 0) e[u].push_back(i);
  }

  dfs(1);

  cin >> m;

  SegTree seg(n);
  while(m--) {
    pair<ll, ll> query;
    cin >> query.first >> query.second;
    if(query.first == 1) {
      if(in[query.second] == out[query.second]) continue;
      seg.update(in[query.second] + 1, out[query.second], 1);
    } else if(query.first == 2) {
      if(in[query.second] == out[query.second]) continue;
      seg.update(in[query.second] + 1, out[query.second], -1);
    } else {
      #ifdef DEBUG
      cout << "\nAns: ";
      #endif
      if(in[query.second] == out[query.second]) {
        cout << 0 << '\n';
      } else {
        cout << seg.query(in[query.second] + 1, out[query.second]) << '\n';
      }
    }
  }
  
  return 0;
}