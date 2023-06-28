#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, a, t;
vector<tuple<ll, ll, ll>> sus;
set<ll> used_e;
map<ll, ll> comp;
vector<ll> answers;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree(ll n) {
    tree.assign(n * 4, -INF);
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
      ll mid = (start + end) / 2;
      return tree[node] = max(update(node * 2, start, mid, target, value), update(node * 2 + 1, mid + 1, end, target, value));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return -INF;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      return max(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  sus.resize(n);
  answers.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a >> t;
    sus[i] = {a, a + t, i};
    used_e.insert(a + t);
  }
  
  ll id = 0;
  for(ll e: used_e) {
    comp[e] = id++;
  }
  for(auto& [_, e, __]: sus) {
    e = comp[e];
  }
  
  sort(sus.begin(), sus.end(), [](auto &a, auto &b) {
    auto [a_s, a_e, _] = a;
    auto [b_s, b_e, __] = b;
    return a_s != b_s ? a_s < b_s : a_e > b_e;
  });

  SegTree seg(id);

  for(auto [s, e, index]: sus) {
    ll most_convincing = seg.query(e);
    if(most_convincing != -INF) {
      answers[index] = most_convincing + 1;
    } else {
      answers[index] = 0;
    }
    
    seg.update(e, answers[index]);
  }

  for(ll answer: answers) {
    cout << answer << ' ';
  }

  
  return 0;
}