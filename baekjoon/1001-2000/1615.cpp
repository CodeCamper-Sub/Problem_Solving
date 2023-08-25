#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<pair<ll, ll>> e;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree(ll n) {
    tree.assign(n * 4, 0);
    root = 1;
    start = 0;
    end = n - 1;  
  }
  
  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  ll query(ll left) {
    if(left == end) return 0;
    return query(root, start, end, left + 1, end);
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll delta) {
    if(target < start || end < target) return tree[node];
    else if(start == end) return tree[node] += delta;
    else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(m);
  for(auto& [u, v]: e) {
    cin >> u >> v;
    u--; v--;
  }
  sort(e.begin(), e.end());

  SegTree seg(n);
  ll answer = 0;
  for(auto [u, v]: e) {
    answer += seg.query(v);
    seg.update(v, 1);
  }

  cout << answer << '\n';
  
  return 0;
}