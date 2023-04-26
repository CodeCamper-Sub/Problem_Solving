#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, sy, sx, sd, ey, ex, ed; // d가 0이면 가로, 1이면 세로
vector<vector<char>> grid;
vector<vector<vector<ll>>> visited;
queue<tuple<ll, ll, ll>> q;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

bool is_valid_point(ll y, ll x) {
  if(y >= n || y < 0 || x >= n || x < 0 || grid[y][x] == '1') {
    return false;
  }
  return true;
}

bool is_valid(ll d, ll y, ll x) {
  if(d == 0) {
    return is_valid_point(y, x - 1) && is_valid_point(y, x) && is_valid_point(y, x + 1);
  } else {
    return is_valid_point(y - 1, x) && is_valid_point(y, x) && is_valid_point(y + 1, x);
  }
}

bool can_rotate(ll y, ll x) {
  if(y == 0 || y == n - 1 || x == 0 || x == n - 1) return false;
  for(ll i = -1; i <= 1; i++) {
    for(ll j = -1; j <= 1; j++) {
      if(grid[y + i][x + j] == '1') return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  grid.assign(n + 1, vector<char>(n + 1));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  sy = -1;
  ey = -1;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      if(grid[i][j] == 'B' && sy == -1) {
        if(j + 1 < n && grid[i][j + 1] == 'B') {
          sy = i;
          sx = j + 1;
          sd = 0;
        } else {
          sy = i + 1;
          sx = j;
          sd = 1;
        }
      }
      if(grid[i][j] == 'E' && ey == -1) {
        if(j + 1 < n && grid[i][j + 1] == 'E') {
          ey = i;
          ex = j + 1;
          ed = 0;
        } else {
          ey = i + 1;
          ex = j;
          ed = 1;
        }
      }
    }
  }

  visited.resize(2);
  for_each(visited.begin(), visited.end(), [](auto& layer) {
    layer.assign(n, vector<ll>(n, INF));
  });

  visited[sd][sy][sx] = 0;
  q.push({sd, sy, sx});
  while(q.size()) {
    auto [d, y, x] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      ll nd = d, ny = y + dy[k], nx = x + dx[k];
      if(is_valid(nd, ny, nx) && visited[nd][ny][nx] > visited[d][y][x] + 1) {
        visited[nd][ny][nx] = visited[d][y][x] + 1;
        q.push({nd, ny, nx});
      }
    }
    if(can_rotate(y, x)) {
      ll nd = 1 - d, ny = y, nx = x;
      if(is_valid(nd, ny, nx) && visited[nd][ny][nx] > visited[d][y][x] + 1) {
        visited[nd][ny][nx] = visited[d][y][x] + 1;
        q.push({nd, ny, nx});
      }
    }
  }
  
  if(visited[ed][ey][ex] == INF) {
    cout << 0 << '\n';
  } else {
    cout << visited[ed][ey][ex] << '\n';
  }
  
  return 0;
}