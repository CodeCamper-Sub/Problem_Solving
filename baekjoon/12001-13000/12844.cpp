#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree, lazy, arr;
  ll root, start, end;
  SegTree(vector<ll> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    lazy.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size() - 1;
    build_tree(root, start, end);
  }
  void update(ll left, ll right, ll k) {
    update(root, start, end, left, right, k);
  }

  ll query(ll left, ll right) {
    return query(root ,start, end, left, right);
  }

  private:
  void propagate(ll node, ll start, ll end) {
    if(lazy[node] == 0) return;
    if((end - start + 1) % 2) tree[node] ^= lazy[node];
    if(start != end) {
      lazy[node * 2] ^= lazy[node];
      lazy[node * 2 + 1] ^= lazy[node];
    }
    lazy[node] = 0;
  }

  ll build_tree(ll node, ll start, ll end) {
    lazy[node] = 0;
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = build_tree(node * 2, start, mid) ^ build_tree(node * 2 + 1, mid + 1, end);
    }
  }

  ll update(ll node, ll start, ll end, ll left, ll right, ll k) {
    propagate(node, start, end);
    if(right < start || end < left) {
      return tree[node];
    } else if(left <= start && end <= right) {
      lazy[node] ^= k;
      propagate(node, start, end);
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return tree[node] = update(node * 2, start, mid, left, right, k) ^ update(node * 2 + 1, mid + 1, end, left, right, k);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    propagate(node, start, end);
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

ll n, m;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  arr.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }

  SegTree seg(arr);
  cin >> m;
  while(m--) {
    ll c, i, j, k;
    cin >> c;
    if(c == 1) {
      cin >> i >> j >> k;
      seg.update(i, j, k);
    } else {
      cin >> i >> j;
      #ifdef DEBUG
      cout << "\nAns: ";
      #endif
      cout << seg.query(i, j) << '\n';
    }
  }
  
  return 0;
}