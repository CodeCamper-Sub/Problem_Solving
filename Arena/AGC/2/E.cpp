#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9+7)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    root = 1;
    start = 0;
    end = n -1;
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
    else if(start == end) {
      return tree[node] = (tree[node] + delta) % MOD;
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = (update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta)) % MOD;
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return 0;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      return (query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right)) % MOD;
    }
  }
};

ll m, k, n;
vector<pair<ll, vector<ll>>> input;
unordered_map<ll, ll> comp;
vector<ll> used;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m;
  input.resize(m);
  for(ll i = 0; i < m; i++) {
    cin >> input[i].first >> n;
    input[i].second.resize(n);
    for(ll j = 0; j < n; j++) {
      cin >> input[i].second[j];
      used.push_back(input[i].second[j]);
    }
  }

  sort(used.begin(), used.end());
  used.erase(unique(used.begin(), used.end()), used.end());
  ll id = 0;
  for(ll i = 0; i < used.size(); i++) {
    comp[used[i]] = id++;
  }

  SegTree seg(id);
  ll answer = 0;
  for(ll i = 0; i < m; i++) {
    k = input[i].first;
    vector<pair<ll, ll>> v;
    for(ll j = 0; j < input[i].second.size(); j++) {
      input[i].second[j] = comp[input[i].second[j]];
      v.push_back({input[i].second[j], j});
    }

    sort(v.begin(), v.end(), [](auto a, auto b) {
      return a.first != b.first ? a.first > b.first : a.second > b.second;
    });

    SegTree lpos_seg(v.size());
    for(auto [_, pos]: v) {
      ll a = lpos_seg.query(0, pos);
      answer += k * (k + 1) / 2 % MOD * a % MOD;
      answer %= MOD;
      lpos_seg.update(pos, 1);
    }

    sort(v.begin(), v.end(), [](auto a, auto b) {
      return a.first != b.first ? a.first > b.first : a.second < b.second;
    });

    SegTree rpos_seg(v.size());
    for(auto [_, pos]: v) {
      ll b = rpos_seg.query(pos, v.size() - 1);
      answer += k * (k - 1) / 2 % MOD * b % MOD;
      answer %= MOD;
      rpos_seg.update(pos, 1);
    }

    for(auto [value, _]: v) {
      ll c = seg.query(value + 1, id - 1);
      answer += k * c;
      answer %= MOD;
    }

    for(auto [value, _] : v) {
      seg.update(value, k);
    }
  }

  cout << answer << '\n';
  
  return 0;
}