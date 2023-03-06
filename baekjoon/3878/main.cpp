#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  bool operator<=(const Point& rhs) {
    return x != rhs.x ? x < rhs.x : y <= rhs.y;
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
    if(v.size() == 1) {
      v.push_back(v.back());
      this->v = v;
      this->ch = v;
      return;
    }

    sort(v.begin(), v.end(), [](Point a, Point b) {
      return a.y != b.y ? a.y < b.y : a.x < b.x;
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
  ll ccw_a_b = ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b);
  ll ccw_b_a = ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b);

  if(ccw_a_b == 0 && ccw_b_a == 0) {
    if(a.b <= a.a) 
      swap(a.a, a.b);
    if(b.b <= b.a) 
      swap(b.a, b.b);
    return b.a <= a.b && a.a <= b.b;
  }

  return ccw_a_b <= 0 && ccw_b_a <= 0;
}

bool inner(const vector<Point>& hull, Point p) {
  ll s = ccw(hull[0], hull[1], p);
  for(ll i = 1; i < hull.size(); i++) {
    if(s * ccw(hull[i], hull[(i + 1) % hull.size()], p) <= 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> T;
  while(T--) {
    cin >> n >> m;

    vector<Point> black_points, white_points;
    for(ll i = 0; i < n; i++) {
      Point p;
      cin >> p.x >> p.y;
      black_points.push_back(p);
    }

    for(ll i = 0; i < m; i++) {
      Point p;
      cin >> p.x >> p.y;
      white_points.push_back(p);
    }

    if(n == 0 || m == 0 || (n == 1 && m == 1)) {
      cout << "YES\n";
      continue;
    }

    ConvexHull black(black_points), white(white_points);

    bool is_possible = true;
    for(ll i = 0; i < black.ch.size(); i++) {
      for(ll j = 0; j < white.ch.size(); j++) {
        Line a(black.ch[i], black.ch[(i+1)%black.ch.size()]);
        Line b(white.ch[j], white.ch[(j+1)%white.ch.size()]);
        if(has_intersection(a, b)) {
          is_possible = false;
          break;
        }
      }
      if(!is_possible) break;
    }

    bool black_include_white = false;
    for(ll i = 0; i < white.ch.size(); i++) {
      if(inner(black.ch, white.ch[i])) {
        black_include_white = true;
      }
    }
    
    bool white_include_black = false;
    for(ll i = 0; i < black.ch.size(); i++) {
      if(inner(white.ch, black.ch[i])) {
        white_include_black = true;
      }
    }

    if(black_include_white || white_include_black) {
      is_possible = false;
    }

    #ifdef DEBUG
    cout << "\n\t\t> Ans: ";
    #endif

    cout << (is_possible ? "YES" : "NO") << '\n';
  }
  
  return 0;
}