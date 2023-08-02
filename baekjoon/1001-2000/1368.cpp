#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<tuple<ll, ll, ll>> e;
vector<ll> w, parent;

ll Find(ll a) {
  if(parent[a] == a) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  w.resize(n + 1);
  parent.resize(n + 1);
  iota(parent.begin(), parent.end(), 0);
  for(ll i = 1; i <= n; i++) {
    cin >> w[i];
    e.push_back({w[i], 0, i});
  }

  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      ll c;
      cin >> c;
      if(i >= j) continue;
      e.push_back({c, i, j});
    }
  }

  sort(e.begin(), e.end());
  ll answer = 0;
  for(auto [c, a, b]: e) {
    if(Find(a) == Find(b)) continue;
    answer += c;
    Union(a, b);
  }

  cout << answer << '\n';
  
  return 0;
}