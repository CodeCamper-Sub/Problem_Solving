#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll x, y;
};

ll tt;
ll n, m;
Point a, b;

void init() {
  cin >> n >> m;
  cin >> a.x >> a.y >> b.x >> b.y;
}

ll minimum(Point p) {
  if((p.x == 1 && p.y == 1) || (p.x == 1 && p.y == m) || (p.x == n && p.y == 1) || (p.x == n && p.y == m)) {
    return 2;
  } else if(p.x == 1 || p.x == n || p.y == 1 || p.y == m) {
    return 3;
  } else {
    return 4;
  }
}

void solve() {
  cout << min(minimum(a), minimum(b)) << '\n';
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