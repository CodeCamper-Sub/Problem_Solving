#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
  if(a < b) swap(a, b);
  if(b == 0) return a;
  return gcd(b, a%b);
}

struct Point {
  ll x, y;

  bool operator<=(Point b) {
    if(x != b.x) {
      return x <= b.x;
    } else {
      return y <= b.y;
    }
  }

  bool operator==(Point b) {
    return x == b.x && y == b.y;
  }
};

struct Line {
  ll a, b, c;

  Line(Point p_1, Point p_2) {
    if(p_1.x == p_2.x) {
      b = 0;
      a = 1;
      c = -p_1.x;
    } else if (p_1.y == p_2.y) {
      a = 0;
      b = 1;
      c = -p_1.y; 
    } else {
      a = -(p_1.y - p_2.y);
      b = (p_1.x - p_2.x);
      c = -(a * p_1.x) - (b * p_1.y);
    }
  }

  pair<double, double> intersection(Line k) {
    pair<double, double> result;

    result.first = double(b * k.c - k.b * c) / double(a * k.b - k.a * b);
    result.second = double(a * k.c - k.a * c) / double(k.a * b - a * k.b);
    
    return result;
  }
};

ll ccw(Point a, Point b, Point c) {
  ll result = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
  if(result > 0) {
    return 1;
  } else if (result == 0) {
    return 0;
  } else {
    return -1;
  }
}

Point p[4];
ll ccw_results[4];
bool is_all_zero = true, is_intersected = true;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(16);

  cin >> p[0].x >> p[0].y >> p[2].x >> p[2].y;
  cin >> p[1].x >> p[1].y >> p[3].x >> p[3].y;

  is_all_zero = true;
  for(ll i = 0; i < 4; i++) {
    ccw_results[i] = ccw(p[i], p[(i+1)%4], p[(i+2)%4]);
    if(ccw_results[i] != 0) is_all_zero = false;
  }

  is_intersected = true;
  if(!is_all_zero) {
    for(ll i = 0; i < 4; i++) {
      if(ccw_results[i] * ccw_results[(i+1)%4] < 0) {
        is_intersected = false;
      }
    }
  } else {
    if(p[2] <= p[0]) {
      swap(p[0], p[2]);
    }
    if(p[3] <= p[1]) {
      swap(p[1], p[3]);
    }
    if(p[1] <= p[2] && p[0] <= p[3]) {
      is_intersected = true;
    } else {
      is_intersected = false;
    }
  }

  if(!is_intersected) {
    cout << 0 << '\n';
  } else {
    cout << 1 << '\n';
    if(!is_all_zero) {
      Line a = Line(p[0], p[2]);
      Line b = Line(p[1], p[3]);
      pair<double, double> intersection = a.intersection(b);
      cout << intersection.first << ' ' << intersection.second << '\n';
    } else {
      if(p[2] == p[1]) {
        cout << p[1].x << ' ' << p[1].y << '\n';
      } else if(p[0] == p[3]) {
        cout << p[0].x << ' ' << p[0].y << '\n';
      }
    }
  }



  return 0;
}