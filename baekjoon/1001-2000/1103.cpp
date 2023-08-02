#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m;
vector<vector<ll>> grid, e;
vector<bool> visited;
vector<ll> dist;

ll flatten(ll y, ll x) {
  return y * m + x;
}

ll dfs(ll now) {
  if(dist[now] != -1) return dist[now];
  dist[now] = 0;
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      dfs(next);
      visited[next] = false;
      dist[now] = max(dist[now], dist[next] + 1);
    } else {
      dist[now] = INF;
      break;
    }
  }
  return dist[now];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      if(c != 'H') {
        grid[i][j] = c - '0';
      } else {
        grid[i][j] = -1;
      }
    }
  }

  e.resize(n * m);
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      if(grid[i][j] == -1) continue;
      if(i - grid[i][j] >= 0 && grid[i - grid[i][j]][j] != -1) {
        e[flatten(i, j)].push_back(flatten(i - grid[i][j], j));
      }
      if(i + grid[i][j] < n && grid[i + grid[i][j]][j] != -1) { 
        e[flatten(i, j)].push_back(flatten(i + grid[i][j], j));
      }
      if(j - grid[i][j] >= 0 && grid[i][j - grid[i][j]] != -1) {
        e[flatten(i, j)].push_back(flatten(i, j - grid[i][j]));
      }
      if(j + grid[i][j] < m && grid[i][j + grid[i][j]] != -1) {
        e[flatten(i, j)].push_back(flatten(i, j + grid[i][j]));
      }
    }
  }

  visited.assign(n * m, false);
  dist.assign(n * m, -1);

  visited[0] = true;
  dfs(0);
  if(dist[0] >= INF) {
    cout << -1 << '\n';
  } else {
    cout << dist[0] + 1 << '\n';
  }
  
  return 0;
}