#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

struct Point;
ll n;
vector<Point> v, hull;

struct Point {
  ll y, x;
};

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll direction(Point a, Point b) {
  // 0 : 0이상 90 미만
  if(a.y <= b.y && a.x < b.x) return 0;
  // 1 : 90이상 180 미만..
  else if(a.y < b.y && b.x <= a.x) return 1;
  else if(b.y <= a.y && b.x < a.x) return 2;
  else return 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  if(n == 1) {
    cout << "4\n";
    return 0;
  }
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }

  sort(v.begin(), v.end(), [](Point& a, Point& b) {
    return a.y != b.y ? a.y < b.y : a.x < b.x;
  });

  sort(v.begin() + 1, v.end(), [](Point& a, Point& b) {
    ll c = ccw(v[0], a, b);
    return c != 0 ? c > 0 : dist(v[0], a) < dist(v[0], b);
  });

  hull.push_back(v[0]);
  hull.push_back(v[1]);
  for(ll i = 2; i < v.size(); i++) {
    while(hull.size() >= 2) {
      Point second = hull.back(); hull.pop_back();
      Point first = hull.back();
      if(ccw(first, second, v[i]) >= 0) {
        hull.push_back(second);
        break;
      }
    }
    hull.push_back(v[i]);
  }

  ll answer = 0;
  bool is_on_line = true;
  for(ll i = 0; i < hull.size(); i++) {
    Point now = hull[i];
    Point next = hull[(i + 1) % hull.size()];
    ll dy = abs(now.y - next.y);
    ll dx = abs(now.x - next.x);
    answer += max(dy, dx);
    if(dy != dx) is_on_line = false;
  }
  
  answer += 4;
  if(is_on_line) answer++;

  cout << answer << '\n';
  
  return 0;
}