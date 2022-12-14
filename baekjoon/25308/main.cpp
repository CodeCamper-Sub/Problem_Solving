#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll arr[10];
ll visited[10], cnt;
vector<ll> result;

struct Point {
  double y, x;
};

Point to_point(ll index, ll value) {
  Point p;
  double radian = (45 * index) * M_PI / 180;
  p.y = value * cos(radian);
  p.x = value * sin(radian);
  if(index % 4 == 0) p.x = 0;
  else if(index % 4 == 2) p.y = 0;
  return p;
}

double ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

bool check_convex_hull() {
  for(ll i = 0; i < 8; i++) {
    Point a = to_point(i, result[i]);
    Point b = to_point((i+1)%8, result[(i+1)%8]);
    Point c = to_point((i+2)%8, result[(i+2)%8]);
    if(ccw(a, b, c) > 0) {
      return false;
    }
  }
  return true;
}

void permutation() {
  if(result.size() == 8) {
    if(check_convex_hull()) {
      cnt++;
    }
    return;
  }
  for(ll i = 0; i < 8; i++) {
    if(visited[i] == 0) {
      visited[i] = 1;
      result.push_back(arr[i]);
      permutation();
      visited[i] = 0;
      result.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 0; i < 8; i++) {
    cin >> arr[i];
  }

  permutation();

  cout << cnt << '\n';

  return 0;
}