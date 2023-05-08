#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;

void init() {
  cin >> n;
}

void solve() {
  for(ll i = n / 2; i >= 1; i--) {
    cout << i << ' ' << i + n / 2 << ' ';
  }
  if(n % 2) {
    cout << n;
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