#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, b, inv, tracking;
vector<pair<ll, ll>> lis;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  a.resize(n);
  b.resize(n);
  inv.resize(n + 1);
  for(ll& a: a) cin >> a;
  for(ll i = 0; i < n; i++) {
    cin >> b[i];
    assert(b[i] <= n);
    inv[b[i]] = i;
  }
  for(ll i = 0; i < n; i++) {
    a[i] = inv[a[i]];
  }
  
  lis.push_back({a[0], 0});
  tracking.assign(n, -1);
  for(ll i = 1; i < n; i++) {
    if(lis.back().first < a[i]) {
      tracking[i] = lis.back().second;
      lis.push_back({a[i], i});
    } else {
      auto iter = lower_bound(lis.begin(), lis.end(), make_pair(a[i], 0ll));
			if(iter == lis.begin()) {
				tracking[i] = -1;
			} else {
				tracking[i] = (iter - 1)->second;
			}
      *iter = {a[i], i};
    }
  }

  vector<ll> result;
  result.push_back(lis.back().second);
  while(tracking[result.back()] != -1) {
    result.push_back(tracking[result.back()]);
  }
  for(ll i = 0; i < result.size(); i++) {
    result[i] = b[a[result[i]]];
  }
  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for(ll i = 0; i < result.size(); i++) {
    cout << result[i] << ' ';
  }
  
  return 0;
}