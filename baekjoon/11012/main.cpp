#include <bits/stdc++.h>
#define INF 999999999999
#define COORD_MAX 100000
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

struct Square {
  Point p1, p2;
};

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree() {
    tree = vector<ll>(COORD_MAX * 4);
    root = 1;
    start = 0;
    end = COORD_MAX;
  }
  public:
  ll query(ll target) {
    return query(root, start, end, target);
  }

  void update(ll left, ll right, ll value) {
    update(root, start, end, left, right, value);
  }

  private:
  ll query(ll node, ll start, ll end, ll target) {
    if(target < start || end < target) {
      return 0;
    } else if (start == end) {
      return tree[node];
    } else {
      ll mid = (start + end) / 2;
      return tree[node] + query(node * 2, start, mid, target) + query(node * 2 + 1, mid + 1, end, target);
    }
  }

  void update(ll node, ll start, ll end, ll left, ll right, ll value) {
    if(right < start || end < left) {
      return;
    } else if(left <= start && end <= right) {
      tree[node] += value;
    } else {
      ll mid = (start + end) / 2;
      update(node * 2, start, mid, left, right, value);
      update(node * 2 + 1, mid + 1, end, left, right, value);
    }
  }
};

ll tt, n, m, answer;
Point p;
Square s;
vector<tuple<ll, ll, ll, ll>> v; // {x, left, right, delta} delta가 0이면 query, 1 또는 -1이면 update

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    answer = 0;
    v.clear();
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
      Point p;
      cin >> p.x >> p.y;
      v.push_back({p.x, p.y, p.y, 0});
    }

    for(ll i = 0; i < m; i++) {
      cin >> s.p1.x >> s.p2.x >> s.p1.y >> s.p2.y;
      v.push_back({s.p1.x, s.p1.y, s.p2.y, 1});
      v.push_back({s.p2.x, s.p1.y, s.p2.y, -1});
    }
    sort(v.begin(), v.end(), [](auto a, auto b){
      if(get<0>(a) != get<0>(b)) {
        return get<0>(a) < get<0>(b);
      } else {
        return get<3>(a) > get<3>(b);
      }
    });

    SegTree seg;
    for(ll i = 0; i < v.size(); i++) {
      auto [x, left, right, delta] = v[i];
      if(delta == 0) {
        answer += seg.query(right);
      } else {
        seg.update(left, right, delta);
      }
    }
    #ifdef DEBUG
    cout << "\nAns: ";
    #endif
    cout << answer << '\n';
  }
  
  return 0;
}