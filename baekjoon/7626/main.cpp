#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

struct Square {
  Point p1, p2;
};

ll n, prev_x, answer;
vector<Square> squares;
set<ll> used_y;
unordered_map<ll, ll> y_comp, y_comp_inv;
vector<tuple<ll, ll, ll, ll>> v; // {x, comp(left), comp(right), value}

struct SegTree {
  vector<ll> overlap_cnt_tree, node_cnt_tree;
  ll root, start, end;

  SegTree(ll n) {
    overlap_cnt_tree = vector<ll>(n * 4);
    node_cnt_tree = vector<ll>(n * 4);
    root = 1;
    start = 0;
    end = n;
  }

  public:
  ll query() {
    return node_cnt_tree[root];
  }

  void update(ll left, ll right, ll value) {
    update(root, start, end, left, right, value);
  }

  private:
  void update(ll node, ll start, ll end, ll left, ll right, ll value) {
    if(right < start || end < left) {
      return;
    } else if(left <= start && end <= right) {
      overlap_cnt_tree[node] += value;
    } else {
      ll mid = (start + end) / 2;
      update(node * 2, start, mid, left, right, value);
      update(node * 2 + 1, mid + 1, end, left, right, value);
    }

    if(overlap_cnt_tree[node] > 0) {
      if(y_comp_inv[end + 1] != NULL) {
        node_cnt_tree[node] = y_comp_inv[end + 1] - y_comp_inv[start];
      } else {
        node_cnt_tree[node] = y_comp_inv[end] - y_comp_inv[start] + 1;
      }
    } else {
      if(start == end) {
        node_cnt_tree[node] = 0;
      } else {
        node_cnt_tree[node] = node_cnt_tree[node * 2] + node_cnt_tree[node * 2 + 1];
      }
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(ll i = 0; i < n; i++) {
    Square s;
    cin >> s.p1.x >> s.p2.x >> s.p1.y >> s.p2.y;
    used_y.insert(s.p1.y);
    used_y.insert(s.p2.y);
    squares.push_back(s);
  }

  ll y_cnt = 0;
  for(ll y: used_y) {
    if(y_comp[y] == NULL) {
      y_comp_inv[y_cnt] = y;
      y_comp[y] = y_cnt++;
    }
  }

  for(ll i = 0; i < squares.size(); i++) {
    Square s = squares[i];
    v.push_back({s.p1.x, y_comp[s.p1.y], y_comp[s.p2.y], 1});
    v.push_back({s.p2.x, y_comp[s.p1.y], y_comp[s.p2.y], -1});
  }

  sort(v.begin(), v.end());

  SegTree seg(used_y.size() - 1);
  prev_x = -INF;
  answer = 0;
  for(ll i = 0; i < v.size(); i++) {
    auto [x, left, right, value] = v[i];
    if(prev_x != -INF) {
      answer += (x - prev_x) * seg.query();
    }
    seg.update(left, right - 1, value);
    prev_x = x;
  }

  cout << answer << '\n';

  return 0;
}