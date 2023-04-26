#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, cnt;

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
  ll maxi = *max_element(a.begin(), a.end());
  cnt.assign(maxi + 1, 0);
}

void solve() {
  for(ll i = 0; i < n; i++) {
    cnt[a[i]]++;
  }
  if(cnt[0] - 1 <= n - cnt[0]) {
    cout << 0 << '\n';
  } else if(cnt[0] > 0 && cnt[1] > 0 && cnt[0] + cnt[1] == n) {
    cout << 2 << '\n';
  } else {
    cout << 1 << '\n';
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