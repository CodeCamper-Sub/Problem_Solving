#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
}
void solve() {
  ll result = a[0];
  for(ll i = 1; i < n; i++) {
    result ^= a[i];
  }
  if(n % 2 == 0) {
    if(result == 0) {
      cout << 0 << '\n';
    } else {
      cout << -1 << '\n';
    }
  } else {
    cout << result << '\n';
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