#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 100100
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree, lazy;
  ll root, start, end;
  SegTree(ll n) {
    tree.assign(n * 4, 0);
    lazy.assign(n * 4, 0);
    root = 1;
    start = 1;
    end = n;
  }

  ll query(ll target) {
    return query(root, start, end, target);
  }

  void update(ll left, ll right, ll delta) {
    update(root, start, end, left, right, delta);
  }

  private:
  void propagate_lazy(ll node, ll start, ll end) {
    if(lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);
    if(start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  ll query(ll node, ll start, ll end, ll target) {
    propagate_lazy(node, start, end);
    if(target < start || end < target) {
      return 0;
    } else if (start == end) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return query(node * 2, start, mid, target) + query(node * 2 + 1, mid + 1, end, target);
    }
  }

  ll update(ll node, ll start, ll end, ll left ,ll right, ll delta) {
    propagate_lazy(node, start, end);
    if(right < start || end < left) {
      return tree[node];
    } else if(left <= start && end <= right) {
      lazy[node] += delta;
      propagate_lazy(node, start, end);
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = update(node * 2, start, mid, left, right, delta) + update(node * 2 + 1, mid + 1, end, left, right, delta);
    }
  }
};

ll n, m, root, c, a, b, in[MAX], out[MAX], cnt;
vector<ll> e[MAX];

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
  for(ll i = 1; i <= n; i++) {
    cin >> c;
    if(c > 0) e[c].push_back(i);
    else root = i;
  }

  dfs(root);
  SegTree seg(n);
  while(m--) {
    cin >> c;
    if(c == 1) {
      cin >> a >> b;
      seg.update(in[a], out[a], b);
    } else {
      cin >> a;
      #ifdef DEBUG
      cout << "\nAns: ";
      #endif
      cout << seg.query(in[a]) << '\n';
    }
  }
  
  
  return 0;
}