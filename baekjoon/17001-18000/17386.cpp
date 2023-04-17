#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y > 0 ? 1 : -1;
}

Point p[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> p[0].x >> p[0].y >> p[2].x >> p[2].y;
  cin >> p[1].x >> p[1].y >> p[3].x >> p[3].y;
  ll standard = ccw(p[0], p[1], p[2]);
  bool flag = true;
  for(ll i = 1; i < 4; i++) {
    if(standard * ccw(p[i], p[(i+1)%4], p[(i+2)%4]) < 0) {
      flag = false;
    }
  }
  if(flag) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}