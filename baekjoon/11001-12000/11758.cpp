#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

Point p[3];

ll cross_product(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 0; i < 3; i++) {
    cin >> p[i].x >> p[i].y;
  }

  ll ccw = cross_product(p[0], p[1], p[2]);
  
  if(ccw > 0) {
    cout << 1 << '\n';
  } else if (ccw == 0) {
    cout << 0 << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}