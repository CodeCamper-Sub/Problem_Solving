#include <bits/stdc++.h>
#define INF 999999999999
#define MAX_COORDINATE 30000
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

struct SegTree {
  vector<ll> overlap_cnt_tree, node_cnt_tree;
  ll root, start, end;

  SegTree() {
    overlap_cnt_tree = vector<ll>(MAX_COORDINATE * 4);
    node_cnt_tree = vector<ll>(MAX_COORDINATE * 4);
    root = 1;
    start = 0;
    end = MAX_COORDINATE;
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
      node_cnt_tree[node] = end - start + 1;
    } else {
      if(start == end) {
        node_cnt_tree[node] = 0;
      } else {
        node_cnt_tree[node] = node_cnt_tree[node * 2] + node_cnt_tree[node * 2 + 1];
      }
    }
  }
};

ll n, prev_x, answer;
Point p1, p2;
vector<tuple<ll, ll, ll, ll>> v; // {x, start, end, delta}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    p2.y -= 1;
    v.push_back({p1.x, p1.y, p2.y, 1});
    v.push_back({p2.x, p1.y, p2.y, -1});
  }

  sort(v.begin(), v.end());

  SegTree seg;
  prev_x = -INF;
  answer = 0;
  for(ll i = 0; i < v.size(); i++) {
    auto [now_x, left, right, value] = v[i];
    if(prev_x != -INF) {
      answer += (now_x - prev_x) * seg.query();
    }
    seg.update(left, right, value);
    prev_x = now_x;
  }

  cout << answer << '\n';
  
  return 0;
}