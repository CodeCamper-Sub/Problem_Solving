#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m;
vector<vector<ll>> grid, visited;
vector<ll> parent;
map<pair<ll, ll>, vector<pair<ll, ll>>> switches;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

ll flatten(ll y, ll x) {
  return y * n + x;
}

ll Find(ll a) {
  if(parent[a] == -1) return a;
  return parent[a] = Find(parent[a]);
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
  grid.assign(n + 1, vector<ll>(n + 1, 0));
  visited.assign(n + 1, vector<ll>(n + 1, 0));
  parent.assign((n + 1) * n + 1, -1);
  for(ll i = 0; i < m; i++) {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    switches[{y, x}].push_back({b, a});
  }

  grid[1][1] = true;
  queue<pair<ll, ll>> q;
  visited[1][1] = true;
  q.push({1, 1});
  ll answer = 1;
  while(q.size()) {
    auto [y, x] = q.front();
    q.pop();
    
    if(switches.count({y, x})) {
      for(auto [b, a]: switches[{y, x}]) {
        if(grid[b][a] == 1) continue;
        grid[b][a] = 1;
        answer++;
        for(ll k = 0; k < 4; k++) {
          ll nb = b + dy[k], na = a + dx[k];
          if(nb > n || nb <= 0 || na > n || nb <= 0) continue;
          if(Find(flatten(nb, na)) == Find(flatten(1, 1))) {
            visited[b][a] = true;
            Union(flatten(nb, na), flatten(b, a));
            q.push({b, a});
            break;
          }
        }
      }
    }
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny > n || ny <= 0 || nx > n || nx <= 0 || grid[ny][nx] == 0 || visited[ny][nx]) continue;
      visited[ny][nx] = true;
      Union(flatten(y, x), flatten(ny, nx));
      q.push({ny, nx});
    }
  }

  cout << answer << '\n';
  
  return 0;
}