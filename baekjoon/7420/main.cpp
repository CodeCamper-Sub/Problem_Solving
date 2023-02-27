#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

ll n, l;
vector<Point> v, ch;
double answer = 0;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll euclid_dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double dist(Point a, Point b) {
  return sqrt(euclid_dist(a, b));
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cout << fixed;
  cout.precision(0);

  cin >> n >> l;
  for(ll i = 0; i < n; i++) {
    Point p;
    cin >> p.x >> p.y;
    v.push_back(p);
  }

  sort(v.begin(), v.end(), [](Point a, Point b) {
    if(a.y != b.y) {
      return a.y < b.y;
    }
    return a.x < b.x;
  });
  
  sort(v.begin() + 1, v.end(), [](Point a, Point b) {
    ll c = ccw(v[0], a, b);
    if(c == 0) {
      return euclid_dist(v[0], a) < euclid_dist(v[0], b);
    }
    return c > 0;
  });

  ch.push_back(v[0]);
  ch.push_back(v[1]);

  for(ll i = 0; i < v.size(); i++) {
    while(ch.size() >= 2 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], v[i]) <= 0) {
      ch.pop_back();
    }
    ch.push_back(v[i]);
  }

  for(ll i = 1; i < ch.size(); i++) {
    answer += dist(ch[i-1], ch[i]);
  }
  
  answer += dist(ch.back(), ch[0]);

  answer += 2 * M_PI * l;

  cout << answer << '\n';
  
  return 0;
}