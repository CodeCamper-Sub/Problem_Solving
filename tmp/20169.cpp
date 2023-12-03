#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct Point {
  ll y, x;
};

struct Segment {
  Point s, e;

  bool is_horizontal() {
    if(s.y == e.y) return true;
    else return false;
  }
};

ll n, t;
vector<Segment> v;
unordered_map<ll, ll> cy, cx;
vector<ll> used_y, used_x;
vector<pair<Point, bool>> intersects; // {Point, is_end_point}
vector<vector<tuple<Point, ll, ll>>> y_points, x_points;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> t;
  v.resize(n);
  for(auto& [s, e]: v) {
    cin >> s.y >> s.x >> e.y >> e.x;
    used_y.push_back(s.y);
    used_y.push_back(e.y);
    used_x.push_back(s.x);
    used_x.push_back(e.x);
  }

  sort(used_y.begin(), used_y.end());
  sort(used_x.begin(), used_x.end());
  used_y.erase(unique(used_y.begin(), used_y.end()), used_y.end());
  used_x.erase(unique(used_x.begin(), used_x.end()), used_x.end());

  ll id = 0;
  for(ll y: used_y) cy[y] = id++;
  id = 0;
  for(ll x: used_x) cx[x] = id++;

  for(auto& [s, e]: v) {
    s.y = cy[s.y];
    s.x = cx[s.x];
    e.y = cy[e.y];
    e.x = cx[e.x];
    intersects.push_back({s, false});
    intersects.push_back({e, false});
  }

  for(ll i = 0; i < v.size(); i++) {
    for(ll j = i + 1; j < v.size(); j++) {
      if(v[i].is_horizontal() == v[j].is_horizontal()) continue;
      if(v[i].is_horizontal()) {
        cout << (v[i].s.x < v[j].s.x && v[j].s.x < v[i].e.x && v[j].s.y < v[i].s.y && v[i].s.y < v[j].e.y) << '\n';
        if(v[i].s.x < v[j].s.x && v[j].s.x < v[i].e.x && v[j].s.y < v[i].s.y && v[i].s.y < v[j].e.y)
          intersects.push_back({{v[j].s.x, v[i].s.y}, true});
      } else {
        cout << (v[j].s.x < v[i].s.x && v[i].s.x < v[j].e.x && v[i].s.y < v[j].s.y && v[j].s.y < v[i].e.y) << '\n';
        if(v[j].s.x < v[i].s.x && v[i].s.x < v[j].e.x && v[i].s.y < v[j].s.y && v[j].s.y < v[i].e.y) 
          intersects.push_back({{v[i].s.x, v[j].s.y}, true});
      }
    }
  }

  for(auto [p, is_intersect]: intersects) {
    cout << p.y << ' ' << p.x << ' ' << is_intersect << '\n';
  }
  
  return 0;
}