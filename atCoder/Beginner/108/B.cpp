#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

istream& operator>>(istream& cin, Point& p) {
  cin >> p.x >> p.y;
  return cin;
}

Point p[4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> p[0] >> p[1];
  for(ll i = 2; i < 4; i++) {
    ll dx = p[i - 1].x - p[i - 2].x;
    ll dy = p[i - 1].y - p[i - 2].y;
    ll ndx = -dy;
    ll ndy = dx;
    p[i].x = p[i - 1].x + ndx;
    p[i].y = p[i - 1].y + ndy;
  }

  cout << p[2].x << ' ' << p[2].y << ' ' << p[3].x << ' ' << p[3].y << '\n';
  
  return 0;
}