#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, k, c;
vector<ll> truth, parent;
vector<vector<ll>> parties;

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
  
  cin >> n >> m;
  parent.assign(n + 1, -1);
  truth.assign(n + 1, false);
  parties.resize(m);
  cin >> k;
  for(ll i = 0; i < k; i++) {
    ll p;
    cin >> p;
    truth[p] = true;
  }

  for(ll i = 0; i < m; i++) {
    cin >> k;
    parties[i].resize(k);
    for(ll j = 0; j < k; j++) {
      cin >> parties[i][j];
      if(j > 0) {
        Union(parties[i][j - 1], parties[i][j]);
      }
    }
  }

  ll answer = 0;
  for(ll i = 0; i < m; i++) {
    bool is_possible = true;
    for(ll j = 0; j < parties[i].size(); j++){
      for(ll k = 1; k <= n; k++) {
        if(!truth[k]) continue;
        if(Find(k) == Find(parties[i][j])) {
          is_possible = false;
          break;
        }
      }
      if(!is_possible) break;
    }
    if(is_possible) answer++;
  }

  cout << answer << '\n';
  
  return 0;
}