#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m;
vector<vector<ll>> e;
unordered_map<ll, ll> insurance;

ll go(ll now, ll p_insure) {
  ll result = 0;
  if(p_insure > 0 || insurance.count(now)) {
    result += 1;
  }
  for(ll next: e[now]) {
    result += go(next, max(p_insure - 1, insurance[now]));
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.resize(n + 1);
  for(ll i = 2; i <= n; i++) {
    ll p;
    cin >> p;
    e[p].push_back(i);
  }

  for(ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    insurance[x] = max(insurance[x], y);
  }

  cout << go(1, 0);

  return 0;
}