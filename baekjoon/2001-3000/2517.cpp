#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    root = 1;
    start = 0;
    end = n - 1;
  }
  
  void update(ll target) {
    update(root, start, end, target, 1);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  private:
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) >> 1;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) return tree[node];
    else if(start == end) {
      return tree[node] = value;
    } else {
      ll mid = (start + end) >> 1;
      return tree[node] = update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value);
    }
  }
};

ll n, id;
unordered_map<ll, ll> comp;
vector<ll> v;
set<ll> used;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i];
    used.insert(v[i]);
  }
  id = 0;
  for(auto k: used) {
    comp[k] = id++;
  }

  SegTree seg(id);
  for(ll i = 0; i < n; i++) {
    cout << seg.query(comp[v[i]], id - 1) + 1 << '\n';
    seg.update(comp[v[i]]);
  }


  
  return 0;
}