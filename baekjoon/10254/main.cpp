#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;

  ll dist(const Point& rhs) {
    return (rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y);
  }
};

ll tt, n;
vector<Point> v, ch;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll ccw(Point a, Point b, Point c, Point d) {
  d.x -= c.x - b.x;
  d.y -= c.y - b.y;
  return ccw(a, b, d);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while (tt--) {
    v.clear();
    ch.clear();
    cin >> n;
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
        return v[0].dist(a) < v[0].dist(b);
      }
      return c > 0;
    });

    ch.push_back(v[0]);
    ch.push_back(v[1]);

    for(ll i = 2; i < v.size(); i++) {
      while(ch.size() >= 2 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], v[i]) <= 0) {
        ch.pop_back();
      }
      ch.push_back(v[i]);
    }

    ll maximum = -INF;
    Point answer[2];

    ll left = 0, right = 1;
    while(left < ch.size()) {
      ll c = ccw(ch[left], ch[(left+1)%ch.size()], ch[right % ch.size()], ch[(right+1) % ch.size()]);
      if(ch[left].dist(ch[right % ch.size()]) > maximum) {
        maximum = ch[left].dist(ch[right % ch.size()]);
        answer[0] = ch[left];
        answer[1] = ch[right % ch.size()];
      }
      if(c > 0) {
        right++;
      } else {
        left++;
      }
    }

    #ifdef DEBUG
    cout << "\nAns: ";
    #endif
    cout << answer[0].x << ' ' << answer[0].y << ' ' << answer[1].x << ' ' << answer[1].y << '\n';
  }
  
  return 0;
}