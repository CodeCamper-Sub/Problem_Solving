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

  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  ll query() {
    return query(root, start, end);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) return tree[node] = arr[start];
    else {
      ll mid = (start + end) >> 1;
      return tree[node] = min(build_tree(node * 2, start, mid), build_tree(node * 2 + 1, mid + 1, end));
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) return tree[node];
    else if(start == end) return tree[node] = value;
    else {
      ll mid = (start + end) >> 1;
      return tree[node] = min(update(node * 2, start, mid, target, value), update(node * 2 + 1, mid + 1, end, target, value));
    }
  }

  ll query(ll node, ll start, ll end) {
    if(start == end) return start;
    else {
      ll mid = (start + end) >> 1;
      if(tree[node * 2] <= tree[node * 2 + 1]) return query(node * 2, start, mid);
      else return query(node * 2 + 1, mid + 1, end);
    }
  }
};

ll n;
vector<ll> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  arr.resize(n);
  for(ll& a: arr) cin >> a;
  
  SegTree seg(arr);
  ll m;
  cin >> m;
  while(m--) {
    ll c;
    cin >> c;
    if(c == 1) {
      ll i, v;
      cin >> i >> v;
      seg.update(i - 1, v);
    } else {
      cout 
      << seg.query() + 1 << '\n';
    }
  }
  
  return 0;
}