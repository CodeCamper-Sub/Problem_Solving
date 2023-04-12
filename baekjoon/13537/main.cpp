#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree(ll n) {
    tree.assign(n * 4, 0);
    root = 1;
    start = 1;
    end = n;
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  void update(ll target, ll delta) {
    update(root, start, end, target, delta);
  }

  private:
  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) {
      return 0;
    } else if(left <= start && end <= right) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }
  }

  ll update(ll node, ll start, ll end, ll target, ll delta) {
    if(target < start || end < target) {
      return tree[node];
    } else if(start == end) {
      return tree[node] += delta;
    } else {
      ll mid = (start + end) / 2;
      return tree[node] = update(node * 2, start, mid, target, delta) + update(node * 2 + 1, mid + 1, end, target, delta);
    }
  }
};

ll n, m;
vector<pair<ll, ll>> a;
vector<ll> answers;
vector<tuple<ll, ll, ll, ll>> queries;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  a.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }

  cin >> m;
  answers.resize(m);
  queries.resize(m);

  for(ll i = 0; i < m; i++) {
    auto& query = queries[i];
    cin >> get<1>(query) >> get<2>(query) >> get<0>(query);
    get<3>(query) = i;
  }

  sort(a.begin(), a.end());
  
  sort(queries.begin(), queries.end());

  SegTree seg(n);
  for(ll i = queries.size() - 1; i >= 0; i--) {
    auto [k, left, right, index] = queries[i];
    while(a.size() && a.back().first > k) {
      seg.update(a.back().second, 1);
      a.pop_back();
    }
    answers[index] = seg.query(left, right);
  }

  for(ll answer: answers) {
    cout << answer << '\n';
  }


  return 0;
}