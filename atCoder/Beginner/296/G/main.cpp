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

ll n, q;
string answers[200200];
vector<Point> v, ch;
vector<pair<Point, ll>> queries;

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), [](Point a, Point b) {
    return a.y != b.y ? a.y < b.y : a.x < b.x;
  });

  sort(v.begin() + 1, v.end(), [](Point a, Point b) {
    ll c = ccw(v[0], a, b);
    return c == 0 ? dist(v[0], a) < dist(v[0], b) : c > 0;
  });
  
  ch = v;

  cin >> q;
  queries.resize(q);
  for(ll i = 0; i < q; i++) {
    cin >> queries[i].first;
    queries[i].second = i;
  }

  sort(queries.begin(), queries.end(), [](auto a, auto b) {
    return ccw(ch[0], a.first, b.first) > 0;
  });

  ll index = 0;
  for(auto [p, i]: queries) {
    while(index < ch.size() - 1 && ccw(ch[0], ch[index + 1], p) > 0) {
      index++;
    }
    if(index == ch.size() - 1) {
      answers[i] = "OUT";
      continue;
    }
    ll c = ccw(ch[index], ch[index + 1], p);
    if(c > 0) {
      answers[i] = "IN";
    } else if(c == 0) {
      answers[i] = "ON";
    } else {
      answers[i] = "OUT";
    }
  }

  for(ll i = 0; i < q; i++) {
    cout << answers[i] << '\n';
  }
  
  return 0;
}