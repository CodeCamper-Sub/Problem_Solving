#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;

void init() {
  cin >> n;
  a.resize(n);
  for(ll &a: a) cin >> a;
}

void solve() {
  ll mini = 1;
  ll maxi = n;
  ll l = 0, r = n - 1;
  while(l <= r) {
    if(a[l] == mini) {
      l++;
      mini++;
    }
    if(l < n && a[l] == maxi) {
      l++;
      maxi--;
    }
    if(a[r] == mini) {
      r--;
      mini++;
    }
    if(r >= 0 && a[r] == maxi) {
      r--;
      maxi--;
    }

    if(l < n && r >= 0 && a[l] != mini && a[l] != maxi && a[r] != mini && a[r] != maxi) break;
  }
  if(l <= r) {
    cout << l + 1 << ' ' << r + 1 << '\n';
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