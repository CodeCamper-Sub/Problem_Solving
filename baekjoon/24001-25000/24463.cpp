#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, m, sy, sx, ey, ex;
vector<vector<char>> grid;
vector<vector<ll>> dist;
vector<vector<pair<ll, ll>>> tracking;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  grid.resize(n, vector<char>(m));
  sy = -1;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> grid[i][j];
      if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        if(grid[i][j] == '.') {
          if(sy == -1) {
            sy = i; sx = j;
          } else {
            ey = i; ex = j;
          }
        }
      }
      if(grid[i][j] == '.') grid[i][j] = '@';
    }
  }
  
  dist.resize(n, vector<ll>(m, INF));
  tracking.resize(n, vector<pair<ll, ll>>(m));
  queue<pair<ll, ll>> q;
  dist[sy][sx] = 0;
  tracking[sy][sx] = {-1, -1};
  q.push({sy, sx});
  while(q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny >= 0 && ny < n && nx >= 0 && nx <= m && grid[ny][nx] == '@' && dist[ny][nx] > dist[y][x] + 1) {
        dist[ny][nx] = dist[y][x] + 1;
        tracking[ny][nx] = {y, x};
        q.push({ny, nx});
      }
    }
  }

  ll y = ey, x = ex;
  while(y != -1 && x != -1) {
    grid[y][x] = '.';
    tie(y, x) = tracking[y][x];
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }

  
  return 0;
}