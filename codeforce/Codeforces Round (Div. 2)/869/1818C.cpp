#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, q, s, e;
vector<ll> a, ints;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> q;
  a.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 1; i < n - 1; i++) {
    if(a[i - 1] >= a[i] && a[i] >= a[i + 1]) {
      ints.push_back(i);
    }
  }
  while(q--) {
    cin >> s >> e;
    s--; e--;
    auto l = lower_bound(ints.begin(), ints.end(), s + 1);
    auto r = upper_bound(ints.begin(), ints.end(), e - 1);
    ll cnt = 0;
    if(l < r) {
      cnt = r - l;
    }
    cout << e - s + 1 - cnt << '\n';
  }

  
  return 0;
}