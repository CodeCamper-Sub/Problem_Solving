#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  bool operator<(const Point &b) const { 
    if(x != b.x) {
      return x < b.x;
    } else {
      return y < b.y;
    }
  }

  bool operator<=(const Point &b) const {
    if(x != b.x) {
      return x < b.x;
    } else {
      return y <= b.y;
    }
  }

  bool operator==(const Point &b) const {
    return x == b.x && y == b.y;
  }
};

ll ccw(Point a, Point b, Point c) {
  ll result = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
  if (result > 0) {
    return 1;
  } else if (result == 0) {
    return 0;
  } else {
    return -1;
  }
}

Point p[4];
ll ccw_results[4];

bool all_zero() {
  for(ll i = 0; i < 4; i++) {
    if(ccw_results[i] != 0) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> p[0].x >> p[0].y >> p[2].x >> p[2].y;
  cin >> p[1].x >> p[1].y >> p[3].x >> p[3].y;
  ll zero_count = 0;
  for(ll i = 0; i < 4; i++) {
    ccw_results[i] = ccw(p[i], p[(i+1)%4], p[(i+2)%4]);
    if(ccw_results[i] == 0) {
      zero_count++;
    }
  }
  bool flag = true;
  if(zero_count == 0) {
    for(ll i = 0; i < 4; i++) {
      if(ccw_results[0] * ccw_results[i] < 0) {
        flag = false;
      }
    }
  } else if(zero_count == 4) {
    if(p[2] < p[0]) {
      swap(p[0], p[2]);
    }
    if(p[3] < p[1]) {
      swap(p[1], p[3]);
    }
    if(p[1] <= p[2] && p[0] <= p[3]) {
      flag = true;
    } else {
      flag = false;
    }
  } else {
    for(ll i = 0; i < 4; i++) {
      if(ccw_results[i] * ccw_results[(i+2)%4] < 0) {
        flag = false;
      }
    }
  }
  if(flag) {
    cout << 1 << '\n';
  } else {
    cout << 0 << '\n';
  }
  return 0;
}