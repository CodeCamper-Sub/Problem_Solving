#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<tuple<ll, ll, ll>> cubes;
map<ll, map<ll, ll>> mini, maxi;
vector<ll> used;
unordered_map<ll, ll> comp;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    root = 1;
    start = 0;
    end = n;
  }
  
  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  ll query(ll left) {
    return query(root, start, end, left, end);
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) return tree[node];
    else if(start == end) return tree[node] = max(tree[node], value);
    else {
      ll mid = (start + end) >> 1;
      return tree[node] = max(update(node * 2, start, mid, target, value), update(node * 2 + 1, mid + 1, end, target, value));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return -INF;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) >> 1;
      return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  cubes.resize(n);
  for(auto& [h, w, d]: cubes) {
    cin >> h >> w >> d;
    vector<ll> tmp = {h, w, d};
    sort(tmp.begin(), tmp.end());
    h = tmp[0]; w = tmp[1]; d = tmp[2];
    used.push_back(h);
    used.push_back(w);
    used.push_back(d);
  }

  sort(used.begin(), used.end());
  used.erase(unique(used.begin(), used.end()), used.end());
  ll id = 0;
  for(auto u: used) {
    comp[u] = ++id;
  }
  for(auto& [h, w, d]: cubes) {
    h = comp[h]; w = comp[w]; d = comp[d];
    if(mini[h].count(w) == 0) {
      mini[h][w] = d;
    } else {
      mini[h][w] = min(mini[h][w], d);
    }
    maxi[h][w] = max(maxi[h][w], d);
  }


  vector<ll> h_keys;
  for(auto [key, _]: mini) h_keys.push_back(key);

  SegTree seg(id);
  for(ll i = h_keys.size() - 1; i >= 0; i--) {
    ll h = h_keys[i];
    for(auto [w, d]: mini[h]) {
      if(seg.query(w + 1) > d) {
        cout << "Yes\n";
        return 0;
      }
    }
    
    for(auto [w, d]: maxi[h]) {
      seg.update(w, d);
    }
  }

  cout << "No\n";
  
  return 0;
}