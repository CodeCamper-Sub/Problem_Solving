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
    fill(tree.begin(), tree.end(), 0);
    fill(lazy.begin(), lazy.end(), 0);
    root = 1;
    start = 1;
    end = n;
  }

  void update(ll left, ll right) {
    update(root, start, end, left, right);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  void propagate(ll node, ll start, ll end) {
    if(lazy[node] == 0) return;
    tree[node] = (end - start + 1) - tree[node];
    if(start != end) {
      lazy[node * 2] ^= 0 ^ 1;
      lazy[node * 2 + 1] ^= 0 ^ 1;
    }
    lazy[node] = 0;
  }

  ll update(ll node, ll start, ll end, ll left, ll right) {
    propagate(node, start, end);
    if(right < start || end < left) {
      return tree[node];
    } else if (left <= start && end <= right) {
      lazy[node] = 1;
      propagate(node, start, end);
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = update(node * 2, start, mid, left, right) + update(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    propagate(node, start, end);
    if(right < start || end < left) {
      return 0;
    } else if (left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

ll n, m, o, s, t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  SegTree seg(n);
  while(m--) {
    cin >> o >> s >> t;
    if(o == 0) {
      seg.update(s, t);
    } else {
      #ifdef DEBUG
      cout << "\nAns: ";
      #endif
      cout << seg.query(s, t) << '\n';
    }
  }
  
  return 0;
}