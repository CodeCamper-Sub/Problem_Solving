#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;

void init() {
  cin >> n;
}

void solve() {
  if(n == 1) {
    cout << 1 << '\n';
    return;
  } else if(n % 2) {
    cout << -1 << '\n';
    return;
  }
  for(ll i = 1; i <= n - 1; i += 2) {
    cout << i + 1 << ' ' << i << ' ';
  }
  cout << '\n';
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