#include <bits/stdc++.h>
#define MOD ll(1e9)
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

vector<ll> parent, sz;
vector<tuple<ll, ll, ll>> e;
ll n, m, min_cost;

ll Find(ll a) {
  if(parent[a] == a) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  if(a == b) return;
  sz[b] += sz[a];
  sz[a] = 0;
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  parent.resize(n + 1);
  sz.assign(n + 1, 1);
  e.resize(m);
  for(auto& [x, y, w]: e) {
    cin >> x >> y >> w;
    min_cost += w;
  }
  for(ll i = 0; i <= n; i++) parent[i] = i;
  sort(e.begin(), e.end(), [](const auto& a, const auto& b) {
    return get<2>(a) > get<2>(b);
  });

  ll answer = 0;
  for(auto [x, y, w]: e) {
    if(Find(x) != Find(y)) {
      answer += sz[Find(x)] * sz[Find(y)] * min_cost;
      answer %= MOD;
      Union(x, y);
    }
    min_cost -= w;
  }

  cout << answer << '\n';
  
  return 0;
}