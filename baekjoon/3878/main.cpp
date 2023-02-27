#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
  bool is_white;

  bool operator<=(const Point& rhs) {
    return x == rhs.x ? y <= rhs.y : x < rhs.x;
  }

  bool operator!=(const Point& rhs) {
    return x != rhs.x || y != rhs.y;
  }
};

struct Line {
  Point a, b;

  Line(Point a, Point b): a(a), b(b) {}
};

ll ccw(Point a, Point b, Point c);
ll dist(Point a, Point b);

struct ConvexHull {
  vector<Point> v;
  vector<Point> ch;

  ConvexHull(vector<Point> v) {
    if(v.size() < 2) {
      this->v = v;
      this->ch = v;
      return;
    }
    sort(v.begin(), v.end(), [](Point a, Point b) {
      return a.y == b.y ? a.x < b.x : a.y < b.y;
    });

    sort(v.begin() + 1, v.end(), [v](Point a, Point b) {
      ll c = ccw(v[0], a, b);
      return c == 0 ? dist(v[0], a) < dist(v[0], b) : c > 0;
    });

    ch.push_back(v[0]);
    ch.push_back(v[1]);
    
    for(ll i = 2; i < v.size(); i++) {
      while(ch.size() >= 2 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], v[i]) <= 0) {
        ch.pop_back();
      }
      ch.push_back(v[i]);
    }

    this->v = v;
  }
};

ll T, n, m;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool has_intersection(Line a, Line b) {
  Point p[4] = {a.a, b.a, a.b, b.b};
  ll ccws[4];
  bool all_zero = true;
  for(ll i = 0; i < 4; i++) {
    ccws[i] = ccw(p[i], p[(i+1)%4], p[(i+2)%4]);
    all_zero &= ccws[i] == 0;
  }
  if(all_zero) {
    if(p[2] <= p[0]) swap(p[0], p[2]);
    if(p[3] <= p[1]) swap(p[1], p[3]);
    if(p[1] <= p[2] && p[0] <= p[3]) {
      return true;
    } else {
      return false;
    }
  } else {
    bool flag = true;
    for(ll i = 0; i < 4; i++) {
      if(ccws[i] * ccws[(i+1)%4] < 0) {
        flag = false;
        break;
      }
    }

    return flag;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--) {
    cin >> n >> m;

    vector<Point> black_points, white_points, all_points;
    for(ll i = 0; i < n; i++) {
      Point p;
      cin >> p.x >> p.y;
      p.is_white = false;
      black_points.push_back(p);
    }

    for(ll i = 0; i < m; i++) {
      Point p;
      cin >> p.x >> p.y;
      p.is_white = true;
      white_points.push_back(p);
    }

    all_points.insert(all_points.end(), black_points.begin(), black_points.end());
    all_points.insert(all_points.end(), white_points.begin(), white_points.end());

    ConvexHull black(black_points), white(white_points), all(all_points);

    bool is_possible = true;
    if(all.ch.size() == black.ch.size()) {
      is_possible = false;
      for(ll i = 0; i < all.ch.size() && !is_possible; i++) {
        if(all.ch[i] != black.ch[i]) {
          is_possible = true;
        }
      }
    }
    if(all.ch.size() == white.ch.size()) {
      is_possible = false;
      for(ll i = 0; i < all.ch.size() && !is_possible; i++) {
        if(all.ch[i] != white.ch[i]) {
          is_possible = true;
        }
      }
    }

    #ifdef DEBUG
    cout << "\n\t\t>Ans: ";
    #endif
    if(!is_possible) {
      if(n == 0 || m == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
      continue;
    }
    for(ll i = 0; i < black.ch.size() && is_possible && black.ch.size() > 1; i++) {
      for(ll j = 0; j < white.ch.size() && is_possible && white.ch.size() > 1; j++) {
        Line a(black.ch[i], black.ch[(i+1)%black.ch.size()]), b(white.ch[i], white.ch[(i+1)%white.ch.size()]);
        if(has_intersection(a, b)) is_possible = false;
      }
    }

    if(is_possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  
  return 0;
}