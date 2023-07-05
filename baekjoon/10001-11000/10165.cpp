#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m, id, a, b;
set<ll> used;
unordered_map<ll, ll> comp;
vector<ll> answer;
vector<tuple<ll, ll, ll>> routes;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  answer.assign(m, true);
  for(ll i = 0; i < m; i++) {
    cin >> a >> b;
    if(a < b) {
      routes.push_back({a, b, i});
      routes.push_back({a - n, b - n, i});
    } else {
      routes.push_back({a - n, b, i});
    }
  }

  sort(routes.begin(), routes.end(), [](auto& a, auto& b) {
    return get<0>(a) != get<0>(b) ? get<0>(a) < get<0>(b) : get<1>(a) > get<1>(b);
  });

  ll maxi = -INF;
  for(auto [a, b, i]: routes) {
    if(b <= maxi) {
      answer[i] = false;
    }
    maxi = max(maxi, b);
  }

  for(ll i = 0; i < m; i++) {
    if(answer[i]) cout << i + 1 << ' ';
  }
  
  return 0;
}