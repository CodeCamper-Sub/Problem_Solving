#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 10100ll
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree() {
    tree.assign(MAX * 4, 0);
    root = 1;
    start = 0;
    end = MAX - 1;
  }

  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, max(0ll, left), min(MAX - 1, right));
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll delta) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      return tree[node] += delta;
    } else {
      ll mid = (start + end) >> 1;
      return tree[node] = update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) >> 1;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }
};

ll tt, n;
vector<tuple<ll, ll, ll>> v;

void init() {
  v.clear();
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    v.push_back({x, 1, y});
    v.push_back({x + 11, -1, y});
  }
}

void solve() {
  SegTree seg;
  sort(v.begin(), v.end());
  ll answer = -INF;
  for(auto [x, delta, y]: v) {
    seg.update(y, delta);
    if(delta > 0) {
      for(ll i = 0; i <= 10; i++) {
        answer = max(answer, seg.query(y - i, y - i + 10));
      }
    }
  }

  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  
  return 0;
}