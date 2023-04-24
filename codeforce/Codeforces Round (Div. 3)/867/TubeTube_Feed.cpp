#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, t;
vector<ll> a, b;

void init() {
  cin >> n >> t;
  a.resize(n);
  b.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) cin >> b[i];
}

void solve() {
  ll answer = -INF;
  ll maxi = -INF;
  for(ll i = 0; i < n; i++) {
    if(i + a[i] <= t && maxi < b[i]) {
      answer = i;
      maxi = b[i];
    }
  }
  if(answer != -INF) {
    cout << answer + 1 << '\n';
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