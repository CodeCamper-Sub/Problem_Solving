#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree, arr;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    arr.resize(n + 1);
    root = 1;
    start = 1;
    end = n;
  }
  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll delta) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      arr[target] += delta;
      return tree[node] = arr[target];  
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if (left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

ll n, m, root, v, cnt, c, w;
vector<vector<ll>> e;
vector<ll> in, out;

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

  cin >> n >> m;
  e.resize(n + 1);
  in.resize(n + 1);
  out.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> v;
    if(v > 0) {
      e[v].push_back(i);
    } else {
      root = i;
    } 
  }
  dfs(root);
  SegTree seg(n);

  while(m--) {
    cin >> c;
    if(c == 1) {
      cin >> v >> w;
      seg.update(in[v], w);
    } else {
      cin >> v;
      #ifdef DEBUG
      cout << "\nAns: ";
      #endif
      cout << seg.query(in[v], out[v]) << '\n';
    }
  }
  
  return 0;
}