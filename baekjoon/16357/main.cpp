#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

// 최댓값 저장 SegTree
struct SegTree {
  vector<ll> tree, lazy;
  ll root, start, end;
  SegTree(ll size) {
    tree.assign(size * 4, 0);
    lazy.assign(size * 4, 0);
    root = 1;
    start = 0;
    end = size;
  }

  ll query() {
    propagate_lazy(root, start, end);
    return tree[root];
  }

  void update(ll left, ll right, ll delta) {
    update(root, start, end, left, right, delta);
  }

  private:
  void propagate_lazy(ll node, ll start, ll end) {
    if(lazy[node] == 0) return;
    tree[node] += lazy[node];
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
      ll mid = start + end >> 1;
      return tree[node] = max(update(node * 2, start, mid, left, right, delta), update(node * 2 + 1, mid + 1, end, left, right, delta));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    propagate_lazy(node, start, end);
    if(right < start || end < left) {
      return -INF;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = start + end >> 1;
      return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }
};

ll n;
set<ll> used_y;
unordered_map<ll, ll> comp;
vector<pair<ll, ll>> intervals;
vector<tuple<ll, ll, ll>> queries; // {좌표, delta, interval index}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    used_y.insert(y1);
    used_y.insert(y2);
    intervals.push_back({y2, y1});
  }

  ll id = 0;
  for(ll y: used_y) {
    comp[y] = id++;
  }

  SegTree passed(id), ongoing(id);

  for(ll i = 0; i < n; i++) {
    intervals[i].first = comp[intervals[i].first];
    intervals[i].second = comp[intervals[i].second];
    queries.push_back({intervals[i].first, 1, i});
    queries.push_back({intervals[i].second + 1, -1, i});
  }

  sort(queries.begin(), queries.end());
  ll answer = -INF;
  for(auto [now, delta, index]: queries) {
    if(delta == 1) {
      ongoing.update(intervals[index].first, intervals[index].second, 1);
    } else {
      ongoing.update(intervals[index].first, intervals[index].second, -1);
      passed.update(intervals[index].first, intervals[index].second, 1);
    }
    answer = max(answer, passed.query() + ongoing.query());
  }

  cout << answer << '\n';
  
  return 0;
}