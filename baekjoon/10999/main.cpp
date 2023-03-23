#include <bits/stdc++.h>
#define INF 999999999999
typedef __int128_t ll;
using namespace std;

struct SegTree {
  vector<ll> tree, arr, lazy;
  ll root, start, end;
  SegTree(vector<ll> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    lazy.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size() - 1;
    build_tree(root, start, end);
  }

  ll update(ll left, ll right, ll delta) {
    return update(root, start, end, left, right, delta);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    lazy[node] = 0;
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
    }
  }

  void propagate_lazy(ll node, ll start, ll end) {
    if(!lazy[node]) return;
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

  ll query(ll node, ll start, ll end, ll left, ll right) {
    propagate_lazy(node, start, end);
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

long long n, m, k, t, a, b, c, d;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;
  arr.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> t;
    arr[i] = t;
  }

  SegTree seg(arr);
  m += k;
  while(m--) {
    cin >> a;
    if(a == 1) {
      cin >> b >> c >> d;
      seg.update(b, c, d);
    } else {
      cin >> b >> c;
      #ifdef DEBUG
      cout << "\nAns: ";
      #endif
      cout << (long long)(seg.query(b, c)) << '\n';
    }
  }
  
  return 0;
}