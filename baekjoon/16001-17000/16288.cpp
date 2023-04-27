#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<ll> p, lis;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  p.resize(n);
  for(ll& p: p) cin >> p;
  reverse(p.begin(), p.end());
  for(ll i = 0; i < n; i++) {
    if(lis.empty() || lis.back() < p[i]) {
      lis.push_back(p[i]);
    } else {
      auto iter = lower_bound(lis.begin(), lis.end(), p[i]);
      *iter = p[i];
    }
  }

  if(lis.size() <= k) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  
  return 0;
}