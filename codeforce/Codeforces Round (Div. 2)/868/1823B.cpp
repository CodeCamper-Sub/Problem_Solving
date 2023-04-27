#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> p;

void init() {
  cin >> n >> k;
  p.resize(n);
  for(ll& p: p) {
    cin >> p;
    p--;
  }
}

void solve() {
  ll cnt = 0;
  for(ll i = 0; i < n; i++) {
    if(i % k != p[i] % k) cnt++;
  }
  if(cnt == 0) {
    cout << 0 << '\n';
  } else if(cnt == 2) {
    cout << 1 << '\n';
  } else {
    cout << -1 << '\n';
  }
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