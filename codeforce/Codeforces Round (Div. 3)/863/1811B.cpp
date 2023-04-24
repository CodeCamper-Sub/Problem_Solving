#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Point {
  ll y, x;
};  

ll n;
Point s, e;

void init() {
  cin >> n;
  cin >> s.y >> s.x >> e.y >> e.x;
}

void solve() {
  Point dp[4];
  dp[0] = {n / 2, n / 2};
  dp[1] = {n / 2, n / 2 + 1};
  dp[2] = {n / 2 + 1, n / 2};
  dp[3] = {n / 2 + 1, n / 2 + 1};
  ll d1 = INF, d2 = INF;
  for(ll i = 0; i < 4; i++) {
    d1 = min(d1, max(abs(s.y - dp[i].y), abs(s.x - dp[i].x)));
    d2 = min(d2, max(abs(e.y - dp[i].y), abs(e.x - dp[i].x)));
  }

  cout << abs(d1 - d2) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}