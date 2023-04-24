#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, u, v, k;
vector<pair<ll, ll>> p;
vector<vector<ll>> e, dist;
set<ll> blacks;
set<ll> cant;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  e.assign(n + 1, vector<ll>());
  dist.assign(n + 1, vector<ll>(n + 1, INF));
  while(m--) {
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(ll i = 1; i <= n; i++) {
    vector<ll> visited(n + 1, false);
    queue<ll> q;
    dist[i][i] = 0;
    visited[i] = true;
    q.push({i});
    while(q.size()) {
      ll now = q.front();
      q.pop();
      for(ll next: e[now]) {
        if(!visited[next]) {
          dist[i][next] = dist[i][now] + 1;
          visited[next] = true;
          q.push(next);         
        }
      }
    }
  }

  cin >> k;
  p.resize(k);
  for(ll i = 0; i < k; i++) {
    cin >> p[i].first >> p[i].second;
    for(ll j = 1; j <= n; j++) {
      if(dist[p[i].first][j] < p[i].second) {
        cant.insert(j);
      }
    }
  }

  for(ll i = 1; i <= n; i++) {
    if(cant.find(i) == cant.end()) {
      blacks.insert(i);
    }
  }

  bool is_valid = true;
  for(ll i = 0; i < k; i++) {
    bool satisfied = false;
    for(ll j = 1; j <= n; j++) {
      if(dist[p[i].first][j] == p[i].second && blacks.find(j) != blacks.end()) {
        satisfied = true;
        break;
      }
    }
    is_valid &= satisfied;
  }

  if(is_valid) {
    cout << "Yes\n";
    for(ll i = 1; i <= n; i++) {
      if(blacks.find(i) != blacks.end()) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
  } else {
    cout << "No\n";
  }
  
  return 0;
}