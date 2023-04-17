#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  bool operator>(const Point& rhs) {
    return y != rhs.y ? y > rhs.y : x > rhs.x;
  }

  bool operator<=(const Point& rhs) {
    return y != rhs.y ? y < rhs.y : x <= rhs.x;
  }
};

typedef pair<Point, Point> Segment;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

bool has_intersection(Segment a, Segment b) {
  ll ccw_a_b = ccw(a.first, a.second, b.first) * ccw(a.first, a.second, b.second);
  ll ccw_b_a = ccw(b.first, b.second, a.first) * ccw(b.first, b.second, a.second);
  if(ccw_a_b == 0 && ccw_b_a == 0) {
    if(a.first > a.second) swap(a.first, a.second);
    if(b.first > b.second) swap(b.first, b.second);
    return a.first <= b.second && b.first <= a.second;
  }
  return ccw_a_b <= 0 && ccw_b_a <= 0;
}

istream& operator>>(istream& cin, Point& p) {
  cin >> p.x >> p.y;
  return cin;
}

ll tt;
Segment l;
Point square[4];

void init() {
  cin >> l.first >> l.second;
  cin >> square[0] >> square[2];
  square[1] = {square[0].x, square[2].y};
  square[3] = {square[2].x, square[0].y};
}

void solve() {
  for(ll i = 0; i < 4; i++) {
    if(has_intersection(l, {square[i], square[(i + 1) % 4]})) {
      cout << "T\n";
      return;
    }
  }

  sort(square, square + 4, [](auto a, auto b) {
    return a.y != b.y ? a.y < b.y : a.x < b.x;
  });

  swap(square[2], square[3]);
  
  bool square_include_segment = true;
  for(ll i = 0; i < 4; i++) {
    if(ccw(square[i], square[(i + 1) % 4], l.first) <= 0) 
      square_include_segment = false;
  }

  if(square_include_segment) {
    cout << "T\n";
  } else {
    cout << "F\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    init();
    solve();
  }

  return 0;
}