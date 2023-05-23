#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, sy, sx, ey, ex;
vector<vector<char>> grid;
vector<vector<vector<ll>>> visited;

ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};
ll mdy[4] = {-1, 1, 1, -1};
ll mdx[4] = {1, 1, -1, -1};

ll refraction(ll l, ll m) {
  if(l == 0) {
    if(m == 0 || m == 2) return 3;
    else return 2;
  } else if(l == 1) {
    if(m == 0 || m == 2) return 2;
    else return 3;
  } else if(l == 2) {
    if(m == 0 || m == 2) return 1;
    else return 0;
  } else {
    if(m == 0 || m == 2) return 0;
    else return 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  grid.assign(n, vector<char>(n));
  visited.resize(n);
  for_each(visited.begin(), visited.end(), [](auto& layer) {
    layer.assign(n, vector<ll>(4, INF));
  });
  sy = -1;
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
    cin >> grid[i][j];
    if(grid[i][j] == '#'){ 
      if(sy == -1) {
        sy = i;
        sx = j;
      } else {
        ey = i;
        ex = j;
      }
    }
  }

  queue<tuple<ll, ll, ll>> q;
  for(ll k = 0; k < 4; k++) {
    visited[sy][sx][k] = 0;
    q.push({sy, sx, k});
  }

  while(q.size()) {
    auto [y, x, k] = q.front();
    q.pop();
    ll ny = y + dy[k], nx = x + dx[k];
    if(ny < 0 || ny >= n || nx < 0 || nx >= n || grid[ny][nx] == '*' || visited[ny][nx][k] <= visited[y][x][k]) continue;
    visited[ny][nx][k] = visited[y][x][k];
    q.push({ny, nx, k});
    if(grid[ny][nx] == '.') continue;
    for(ll mk = 0; mk < 4; mk++) {
      if(visited[ny][nx][refraction(k, mk)] > visited[ny][nx][k] + 1) {
        visited[ny][nx][refraction(k, mk)] = visited[ny][nx][k] + 1;
        q.push({ny, nx, refraction(k, mk)});
      }
    }
  }

  ll answer = INF;
  for(ll k = 0; k < 4; k++) answer = min(answer, visited[ey][ex][k]);

  cout << answer << '\n';


  
  return 0;
}