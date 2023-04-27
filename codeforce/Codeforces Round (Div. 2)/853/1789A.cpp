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
  ll mini = INF;
  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      mini = min(mini, gcd(a[i], a[j]));
    }
  }
  if(mini <= 2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
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