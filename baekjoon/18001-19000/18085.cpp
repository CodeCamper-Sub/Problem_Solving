#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m;
vector<vector<ll>> nums;
set<ll> used_d;
map<ll, ll> comp, inv;
vector<ll> parent;
ll id = 0;
map<ll, vector<ll>> connected_vertexes;

ll Find(ll a) {
  if(parent[a] == -1) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(ll a, ll b) {
  a = Find(a);
  b = Find(b);
  if(a == b) return;
  parent[a] = b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  nums.resize(n + 1);
  for(ll i = 1; i <= n; i++) {
    cin >> m;
    nums[i].resize(m);
    for(ll j = 0; j < m; j++) {
      cin >> nums[i][j];
      used_d.insert(nums[i][j]);
    }
  }

  id = n + 1;
  for(ll d: used_d) {
    comp[d] = id;
    inv[id++] = d;
  }

  parent.assign(n + used_d.size() + 1, -1);

  for(ll i = 1; i <= n; i++) {
    for(ll& d: nums[i]) {
      d = comp[d];
      if(Find(i) != Find(d)) {
        Union(i, d);
        connected_vertexes[d].push_back(i);
      }
    }
  }

  for(ll i = 1; i <= n; i++) {
    if(Find(1) != Find(i)) {
      cout << "impossible\n";
      return 0;
    }
  }

  for(auto [d, v]: connected_vertexes) {
    for(ll i = 1; i < v.size(); i++) {
      cout << v[0] << ' ' << v[i] << ' ' << inv[d] << '\n';
    }
  }


  
  return 0;
}