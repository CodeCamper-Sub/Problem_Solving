#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, d;
vector<pair<ll, ll>> v;
map<ll, ll> comp, inv;
vector<ll> used;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree(ll n) {
    tree.resize(n * 4);
    root = 1;
    start = 0;
    end = n - 1;
  }

  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
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
  
  cin >> n;
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
    used.push_back(v[i].first);
    used.push_back(v[i].second);
  }
  cin >> d;
  
  sort(used.begin(), used.end());
  used.erase(unique(used.begin(), used.end()), used.end());
  ll id = 0;
  
  for(auto u: used) {
    comp[u] = id;
    inv[id++] = u;
  }

  SegTree seg(id);
  sort(v.begin(), v.end());
  for(ll i = 0; i < v.size(); i++) {
    v[i].first = comp[v[i].first];
    v[i].second = comp[v[i].second];
    seg.update(v[i].second, 1);
  }

  ll now = -1;
  ll answer = 0;
  for(ll i = 0; i < v.size(); i++) {
    if(now == v[i].first) {
      seg.update(v[i].second, -1);
      continue;
    }

    now = v[i].first;
    auto iter = comp.lower_bound(inv[now] + d);
    if(iter == comp.end()) {
      answer = max(answer, seg.query(now, seg.end));
    } else if(iter->first == inv[now] + d) {
      answer = max(answer, seg.query(now, iter->second));
    } else {
      answer = max(answer, seg.query(now, iter->second - 1));
    }
    seg.update(v[i].second, -1);
  }

  cout << answer << '\n';

  
  return 0;
}