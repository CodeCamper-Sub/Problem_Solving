#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree, arr;
  ll root, start, end;
  SegTree(vector<ll> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size() - 1;
    build_tree(root, start, end);
  }
  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  ll query(ll target) {
    return query(root, start, end, target);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) return tree[node] = arr[start];
    ll mid = (start + end) >> 1;
    return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
  }

  ll update(ll node, ll start, ll end, ll target, ll delta) {
    if(target < start || end < target) return tree[node];
    else if(start == end) {
      arr[start] += delta;
      return tree[node] = arr[start];
    }
    ll mid = (start + end) >> 1;
    return tree[node] = update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta);
  }

  ll query(ll node, ll start, ll end, ll target) {
    if(start == end) return start;
    ll mid = (start + end) >> 1;
    if(tree[node * 2] < target) {
      return query(node * 2 + 1, mid + 1, end, target - tree[node * 2]);
    } else {
      return query(node * 2, start, mid, target);
    }
  }
};

ll n, m, c, i, a;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  arr.resize(n);
  for(ll& a: arr) cin >> a;
  SegTree seg(arr);
  cin >> m;
  while(m--) {
    cin >> c;
    if(c == 1) {
      cin >> i >> a;
      seg.update(i - 1, a);
    } else {
      cin >> i;
      cout << seg.query(i) + 1 << '\n';
    }
  }

  
  return 0;
}