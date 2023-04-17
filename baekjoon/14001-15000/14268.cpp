#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 100100
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;
  SegTree(ll n) {
    tree.resize(n * 4);
    fill(tree.begin(), tree.end(), 0);
    root = 1;
    start = 1;
    end = n;
  }

  void update(ll left, ll right, ll delta) {
    update(root, start, end, left, right, delta);
  }

  ll query(ll target) { return query(root, start, end, target); }

private:
  void update(ll node, ll start, ll end, ll left, ll right, ll delta) {
    if (right < start || end < left) {
      return;
    }
    if (left <= start && end <= right) {
      tree[node] += delta;
    } else {
      ll mid = (start + end) / 2;
      update(node * 2, start, mid, left, right, delta);
      update(node * 2 + 1, mid + 1, end, left, right, delta);
    }
  }

  ll query(ll node, ll start, ll end, ll target) {
    if (target < start || end < target) {
      return 0;
    } else if (start == end) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] + query(node * 2, start, mid, target) +
             query(node * 2 + 1, mid + 1, end, target);
    }
  }
};

ll n, m, v, cnt, c, p, w, root;
vector<vector<ll>> e;
vector<pair<ll, ll>> interval;

void dfs(ll now) {
  interval[now].first = ++cnt;
  for (ll next : e[now]) {
    if(interval[next].first == 0) {
      dfs(next);
    }
  }
  interval[now].second = cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  e.resize(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> v;
    if (v > 0) {
      e[v].push_back(i);
    } else {
      root = i;
    }
  }

  interval.resize(n + 1);
  fill(interval.begin(), interval.end(), make_pair(0, 0));

  dfs(root);
  SegTree seg(n);
  for(ll i = 0; i < m; i++) {
    cin >> c;
    if(c == 1) {
      cin >> p >> w;
      seg.update(interval[p].first, interval[p].second, w);
    } else {
      cin >> p;
      #ifdef DEBUG
      cout << "\nAns :";
      #endif
      cout << seg.query(interval[p].first) << '\n';
    }
  }

  return 0;
}