#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll a, b, c, d;

void init() {
  cin >> a >> b >> c >> d;
}

void solve() {
  if(d < b || c - a > d - b) {
    cout << -1 << '\n';
    return;
  }
  ll na = c - (d - b);
  ll answer = a - na + d - b;
  cout << answer << '\n';
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