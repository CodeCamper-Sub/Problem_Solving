#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

ll tt, n, excluded[2020];
vector<pair<Point, ll>> points, ch;
vector<ll> answers;

ll ccw(Point a, Point b, Point c) {
  ll result = a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
  if(result > 0) return 1;
  else if(result == 0) return 0;
  else return -1;
}

ll dist(Point a, Point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

void solve() {
  for(ll i = 0; i < n; i++) {
    Point p;
    cin >> p.x >> p.y;
    points.push_back({p, i});
  }

  sort(points.begin(), points.end(), [](auto _a, auto _b) {
    auto [a, a_index] = _a;
    auto [b, b_index] = _b;
    return a.y != b.y ? a.y < b.y : a.x < b.x;
  });

  sort(points.begin() + 1, points.end(), [](auto _a, auto _b) {
    auto [s, s_index] = points[0];
    auto [a, a_index] = _a;
    auto [b, b_index] = _b;
    ll c = ccw(s, a, b);
    if(c == 0) {
      return dist(s, a) < dist(s, b);
    } else {
      return c > 0;
    }
  });

  ch.push_back(points[0]);
  ch.push_back(points[1]);
  for(ll i = 2; i < points.size(); i++) {
    while(ch.size() >= 2) {
      auto second = ch.back(); ch.pop_back();
      auto first = ch.back();
      if(ccw(first.first, second.first, points[i].first) >= 0) {
        ch.push_back(second);
        break;
      }
    }
    ch.push_back(points[i]);
  }

  for(ll i = 1; i < ch.size(); i++) {
    if(ch[i].first.y <= ch[(i + 1) % ch.size()].first.y) {
      excluded[ch[i].second] = 1;
      answers.push_back(ch[i].second);
    } else {
      break;
    }
  }

  sort(points.begin(), points.end(), [](auto _a, auto _b) {
    auto [a, a_index] = _a;
    auto [b, b_index] = _b;
    return a.y != b.y ? a.y > b.y : a.x > b.x;
  });

  for(ll i = 0; i < points.size(); i++) {
    if(excluded[points[i].second] == 0) {
      answers.push_back(points[i].second);
    }
  }

  while(!answers.empty()) {
    cout << answers.back() << ' ';
    answers.pop_back();
  }
  cout << '\n';
}

void init() {
  points.clear();
  answers.clear();
  ch.clear();
  cin >> n;
  fill(excluded, excluded + n, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  
  return 0;
}