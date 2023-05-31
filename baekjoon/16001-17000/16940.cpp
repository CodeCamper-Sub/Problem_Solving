#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<vector<ll>> e;
vector<ll> visiting, location, path, visited;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  e.assign(n + 1, vector<ll>());
  visiting.assign(n, 0);
  location.assign(n + 1, 0);
  visited.assign(n + 1, false);
  for(ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  
  for(ll i = 0; i < n; i++) {
    cin >> visiting[i];
    location[visiting[i]] = i;
  }

  if(visiting[0] != 1) {
    cout << 0 << '\n';
    return 0;
  }
  for(ll i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end(), [](ll a, ll b) {
      return location[a] < location[b];
    });
  }

  queue<ll> q;
  visited[visiting[0]] = true;
  q.push(visiting[0]);

  while(q.size()) {
    ll now = q.front();
    path.push_back(now);
    q.pop();
    for(ll next: e[now]) {
      if(!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }

  for(ll i = 0; i < n; i++) {
    if(visiting[i] != path[i]) {
      cout << 0 << '\n';
      return 0;
    }
  }

  cout << 1 << '\n';
  
  return 0;
}