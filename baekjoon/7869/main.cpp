#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

double square(double);

struct Circle {
    double x, y, r;
    double theta;

    double distance(Circle another) {
      return sqrt(square(x - another.x) + square(y - another.y));
    }
};

Circle c1, c2;
double intersection_area = 0;

bool too_far() {
  return (c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) >= (c1.r + c2.r) * (c1.r + c2.r);
}

bool is_enclosed() {
  return (c1.x - c2.x)*(c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) <= (c1.r - c2.r) * (c1.r - c2.r);
}

double square(double a) {
  return a * a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed;
  cout.precision(3);

  cin >> c1.x >> c1.y >> c1.r >> c2.x >> c2.y >> c2.r;
  if(c1.r > c2.r) {
    swap(c1, c2);
  }

  if(too_far()) {
    intersection_area = 0;
    cout << intersection_area << '\n';
    return 0;
  }
  if(is_enclosed()) {
    intersection_area = c1.r * c1.r * M_PI;
    cout << intersection_area << '\n';
    return 0;
  }

  double distance = c1.distance(c2);

  c1.theta = acos((square(c1.r) + square(distance) - square(c2.r)) / (2 * c1.r * distance)) * 2;
  c2.theta = acos((square(c2.r) + square(distance) - square(c1.r)) / (2 * c2.r * distance)) * 2;
  
  intersection_area += square(c1.r) * (c1.theta - sin(c1.theta));
  intersection_area += square(c2.r) * (c2.theta - sin(c2.theta));
  intersection_area /= 2;

  cout << intersection_area << '\n';

  return 0;
}