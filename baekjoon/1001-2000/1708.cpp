#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  ll dist(const Point& rhs) const {
    return (this->x - rhs.x) * (this->x - rhs.x) + (this->y - rhs.y) * (this->y - rhs.y);
  }
};

ll n;
vector<Point> v;
vector<Point> s;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    Point p;
    cin >> p.x >> p.y;
    v.push_back(p);
  }

  sort(v.begin(), v.end(), [](Point a, Point b) {
    if(a.y != b.y) {
      return a.y < b.y;
    }
    return a.x < b.x;
  });

  sort(v.begin() + 1, v.end(), [](Point a, Point b) {
    if(ccw(v[0], a, b) != 0) {
      return ccw(v[0], a, b) > 0;
    } else {
      return v[0].dist(a) < v[0].dist(b);
    }
  });

  s.push_back(v[0]);
  s.push_back(v[1]);

  for(ll i = 2; i < v.size(); i++) {
    while(s.size() >= 2 && ccw(s[s.size() - 2], s[s.size() - 1], v[i]) <= 0) {
      s.pop_back();
    }
    s.push_back(v[i]);
  }

  cout << s.size() << '\n';
  
  return 0;
}