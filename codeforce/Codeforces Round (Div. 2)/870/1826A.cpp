#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, l, sum;
vector<ll> cnt;

void init() {
  cin >> n;
  cnt.assign(n + 1, 0);
  sum = 0;
  for(ll i = 0; i < n; i++) {
    cin >> l;
    cnt[l]++;
  }
}

void solve() {
  sum = n;
  for(ll i = 0; i <= n; i++) {
    sum -= cnt[i];
    if(sum == i) {
      cout << i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
  return;
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