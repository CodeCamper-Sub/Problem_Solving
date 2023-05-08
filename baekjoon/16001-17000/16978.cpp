#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<ll> a, answers;
vector<pair<ll, ll>> update_queries;
vector<tuple<ll, ll, ll, ll>> queries;

struct SegTree {
  vector<ll> tree, arr;
  ll root, start, end;
  SegTree(vector<ll> arr): arr(arr) {
    tree.resize(arr.size() * 4);
    root = 1;
    start = 0;
    end = arr.size();
    build_tree(root, start, end);
  }
  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  private:
  ll build_tree(ll node, ll start, ll end) {
    if(start == end) {
      return tree[node] = arr[start];
    } else {
      ll mid = (start + end) >> 1;
      return tree[node] = build_tree(node * 2, start, mid) + build_tree(node * 2 + 1, mid + 1, end);
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if (left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) >> 1;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      return tree[node] = arr[start] = value;
    } else {
      ll mid = (start + end) >> 1;
      return tree[node] = update(node * 2, start, mid, target, value) + update(node * 2 + 1, mid + 1, end, target, value);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  SegTree seg(a);

  cin >> m;
  while(m--) {
    ll c, i, j, k;
    cin >> c;
    if(c == 1) {
      cin >> i >> j;
      update_queries.push_back({i, j});
    } else {
      cin >> k >> i >> j;
      queries.push_back({k, queries.size(), i, j});
    }
  }

  answers.resize(queries.size());
  sort(queries.begin(), queries.end());
  ll now = 0;
  for(auto [k, index, i, j]: queries) {
    while(now < k) {
      seg.update(update_queries[now].first, update_queries[now].second);
      now++;
    }
    answers[index] = seg.query(i, j);
  }

  for(ll answer: answers) {
    cout << answer << '\n';
  }
  
  
  return 0;
}