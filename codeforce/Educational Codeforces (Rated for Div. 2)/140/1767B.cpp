#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
}

void solve() {
  sort(a.begin() + 1, a.end());
  for(ll i = 1; i < n; i++) {
    if(a[0] >= a[i]) continue;
    a[0] = (a[0] + a[i]) / 2 + (a[0] + a[i]) % 2;
  }
  cout << a[0] << '\n';
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