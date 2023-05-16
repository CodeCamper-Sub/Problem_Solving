#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer;
vector<ll> v, cnt;

struct Point {
  ll x, y;
};

ll ccw(Point a, Point b, Point c) {
  return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  cnt.resize(n);
  for(ll& v: v) cin >> v;
  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      bool can_see = true;
      for(ll k = i + 1; k < j; k++) {
        Point a = {i, v[i]};
        Point b = {k, v[k]};
        Point c = {j, v[j]};
        if(ccw(a, b, c) <= 0) {
          can_see = false;
          break;
        }
      }
      if(can_see) {
        answer = max(answer, ++cnt[i]);
        answer = max(answer, ++cnt[j]);
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}