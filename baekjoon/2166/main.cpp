#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
double area;

struct Point {
  ll x;
  ll y;
};

double cross_product(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout.setf(ios::fixed);
  cout.precision(1);

  cin >> n;

  Point start, last, now;
  cin >> start.x >> start.y;
  cin >> last.x >> last.y;

  for(ll i = 2; i < n; i++) {
    cin >> now.x >> now.y;
    area += cross_product(start, last, now) / 2;
    last = now;
  }
  cout << abs(area);

  return 0;
}