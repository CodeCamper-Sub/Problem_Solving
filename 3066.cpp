#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> k;

void init() {
  cin >> n;
  k.resize(n);
  for(ll& k: k) cin >> k;
}

void solve() {
  vector<ll> lis;
  for(ll i = 0; i < n; i++){
    if(lis.empty() || lis.back() < k[i]) {
      lis.push_back(k[i]);
    } else {
      auto iter = lower_bound(lis.begin(), lis.end(), k[i]);
      *iter = k[i];
    }
  }
  cout << lis.size() << '\n';
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