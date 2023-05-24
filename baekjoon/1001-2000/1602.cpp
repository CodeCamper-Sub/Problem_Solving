#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, q;
vector<ll> monkey;
vector<vector<ll>> d, t;
vector<pair<ll, ll>> visit_seq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> q;
  monkey.resize(n + 1);
  d.resize(n + 1, vector<ll>(n + 1, INF));
  t.resize(n + 1, vector<ll>(n + 1, INF));
  for(ll i = 1; i <= n; i++) {
    cin >> monkey[i];
    visit_seq.push_back({monkey[i], i});
    t[i][i] = monkey[i];
  }

  for(ll i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
    d[b][a] = c;
    t[a][b] = max(monkey[a], monkey[b]);
    t[b][a] = max(monkey[a], monkey[b]);
  }
  
  sort(visit_seq.begin(), visit_seq.end());
  for(auto [_, k]: visit_seq) {
    for(ll i = 1; i <= n; i++) {
      for(ll j = 1; j <= n; j++) {
        ll nd = d[i][k] + d[k][j] + max(t[i][k], t[k][j]);
        if(d[i][j] + t[i][j] > d[i][k] + d[k][j] + max(t[i][k], t[k][j])) {
          d[i][j] = d[i][k] + d[k][j];
          t[i][j] = max(t[i][k], t[k][j]);
        }
      }
    }
  }

  while(q--) {
    ll a, b;
    cin >> a >> b;
    if(d[a][b] == INF) {
      cout << -1 << '\n';
    } else {
      cout << d[a][b] + t[a][b] << '\n';
    }
  }
  
  
  return 0;
}