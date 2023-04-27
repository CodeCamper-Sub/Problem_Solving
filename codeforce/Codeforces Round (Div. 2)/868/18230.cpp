#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;

void init() {
  cin >> n >> k;
}

void solve() {
  for(ll i = 0; i <= n; i++) {
    ll partial_k = i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2;
    if(partial_k == k) {
      cout << "YES\n";
      for(ll j = 0; j < i; j++) {
        cout << 1 << ' ';
      }
      for(ll j = i; j < n; j++) {
        cout << -1 << ' ';
      }
      cout << '\n';
      return;
    }
  }
  cout << "NO\n";
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