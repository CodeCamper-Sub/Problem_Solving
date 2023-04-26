#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b;

void init() {
  cin >> n;
  a.resize(n);
  b.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
}
void solve() {
  ll answer = 1;
  ll l = b[0];
  ll g = a[0] * b[0];
  for(ll i = 1; i < n; i++) {
    ll ng = gcd(g, a[i] * b[i]);
    ll nl = lcm(l, b[i]);
    if(ng % nl == 0) {
      g = ng;
      l = nl;
    } else {
      answer++;
      l = b[i];
      g = a[i] * b[i];
    }
  }
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