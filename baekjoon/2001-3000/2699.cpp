#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

ll n;
vector<Point> v, hull;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void init() {
  cin >> n;
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }
  hull.clear();
}

void solve() {
  sort(v.begin(), v.end(), [](Point a, Point b) {
    return a.y != b.y ? a.y > b.y : a.x < b.x;
  });

  sort(v.begin() + 1, v.end(), [](Point a, Point b) {
    ll c = ccw(v[0], a, b);
    return c != 0 ? c > 0 : dist(v[0], a) < dist(v[0], b);
  });

  hull.push_back(v[0]);
  hull.push_back(v[1]);
  for(ll i = 2; i < v.size(); i++) {
    while(hull.size() >= 2) {
      Point second = hull.back(); hull.pop_back();
      Point first = hull.back();
      if(ccw(first, second, v[i]) > 0) {
        hull.push_back(second);
        break;
      }
    }
    hull.push_back(v[i]);
  }
  
  sort(hull.begin(), hull.end(), [](Point a, Point b) {
    return a.y != b.y ? a.y > b.y : a.x < b.x;
  });

  sort(hull.begin() + 1, hull.end(), [](Point a, Point b) {
    return ccw(v[0], a, b) < 0;
  });

  cout << hull.size() << '\n';
  for(auto [x, y]: hull) {
    cout << x << ' ' << y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}