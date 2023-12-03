#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, c, i, v;
vector<ll> arr;

struct SegTree {
  vector<pair<ll, ll>> tree;
  vector<ll> arr;
  ll root, start, end;
  SegTree(vector<ll> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size() - 1;
    build_tree(root, start, end);
  }

  pair<ll, ll> build_tree(ll node, ll start, ll end) {
    if(start == end) return tree[node] = {arr[start], start};
    ll mid = (start + end) / 2;
    pair<ll, ll> left = build_tree(node * 2, start, mid);
    pair<ll, ll> right = build_tree(node * 2 + 1, mid + 1, end);
    if(left.first <= right.first) {
      return tree[node] = left;
    } else {
      return tree[node] = right;
    }
  }

  pair<ll, ll> update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) return tree[node];
    else if(start == end) return tree[node] = {value, start};
    else {
      ll mid = (start + end) / 2;
      pair<ll, ll> left = update(node * 2, start, mid, target, value);
      pair<ll, ll> right = update(node * 2 + 1, mid + 1, end, target, value);
      if(left.first <= right.first) {
        return tree[node] = left;
      } else {
        return tree[node] = right;
      }
    }
  }

  pair<ll, ll> query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return {INF, 0};
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      pair<ll, ll> left_result = query(node * 2, start, mid, left, right);
      pair<ll, ll> right_result = query(node * 2 + 1, mid + 1, end, left, right);
      if(left_result.first <= right_result.first) {
        return left_result;
      } else {
        return right_result;
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  arr.resize(n);
  for(ll& a: arr) cin >> a;
  cin >> m;
  SegTree seg(arr);
  while(m--) {
    cin >> c;
    if(c == 1) {
      cin >> i >> v;
      i--;
      seg.update(seg.root, seg.start, seg.end, i, v);
    } else {
      cin >> i >> v;
      i--;
      v--;
      cout << seg.query(seg.root, seg.start, seg.end, i, v).second + 1 << '\n';
    }
  }
  
  return 0;
}