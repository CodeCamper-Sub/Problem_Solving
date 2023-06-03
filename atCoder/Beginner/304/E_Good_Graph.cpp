#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, k, q;
vector<ll> parent;
map<ll, set<ll>> disjoint;

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
  
  cin >> n >> m;
  parent.resize(n + 1);
  for(ll i = 1; i <= n; i++) parent[i] = i;
  for(ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    Union(u, v);
  }

  bool is_good = true;
  cin >> k;
  for(ll i = 1; i <= n; i++) Find(i);
  for(ll i = 0; i < k; i++) {
    ll x, y;
    cin >> x >> y;
    x = Find(x);
    y = Find(y);
    if(x == y) {
      is_good = false;
    }
    disjoint[x].insert(y);
    disjoint[y].insert(x);
  }
  cin >> q;
  for(ll i = 0; i < q; i++) {
    ll x, y;
    cin >> x >> y;
    if(!is_good) {
      cout << "No\n";
      continue;
    }
    x = Find(x);
    y = Find(y);
    if(disjoint[x].find(y) != disjoint[x].end()) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  
  return 0;
}