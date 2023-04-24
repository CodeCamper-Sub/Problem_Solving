#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, maxi;
unordered_map<ll, ll> m;
vector<ll> a, used;

void init() {
  cin >> n;
  a.resize(n);
  m.clear();
  maxi = -INF;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]]++;
    maxi = max(maxi, a[i]);
  }
  used.clear();
  for(auto [k, _]: m) {
    used.push_back(k);
  }
  sort(used.begin(), used.end());
}

void solve() {
  ll answer = 0;
  for(ll i = 0; i < used.size(); i++) {
    if(m[used[i]] >= 3) {
      answer += m[used[i]] * (m[used[i]] - 1) * (m[used[i]] - 2);
    }
    for(ll b = 2; used[i] * b * b <= maxi;) {
      answer += m[used[i]] * m[used[i] * b] * m[used[i] * b * b];
      auto iter = lower_bound(used.begin(), used.end(), used[i] * (b + 1));
      if(iter == used.end()) break;
      b = *iter / used[i];
    }
  }
  cout << answer << '\n';
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