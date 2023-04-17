#include <bits/stdc++.h>
#define INF 999999999999
#define MAX ll(1e9)
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

ll tt, n, k;
vector<Point> v;

void init() {
  cin >> n >> k;
  v.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
    v[i].y *= 10;
  }
}

void solve() {
  sort(v.begin(), v.end(), [](auto a, auto b) {
    return a.x != b.x ? a.x < b.x : a.y < b.y;
  });
  ll left = 0, right = 2 * MAX;
  while(left <= right) {
    ll mid = (left + right) / 2;
    ll kk = k - 1;
    ll minimum = INF;
    ll maximum = -INF;
    for(auto [x, y]: v) {
      minimum = min(minimum, y);
      maximum = max(maximum, y);
      if(maximum - minimum > 2 * mid) {
        kk--;
        minimum = y;
        maximum = y;
      }
    }
    if(kk >= 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  double answer = left * 0.1 + 0.005;
  cout << answer << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(1);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}