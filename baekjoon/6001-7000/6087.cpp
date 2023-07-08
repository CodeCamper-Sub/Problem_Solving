#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll w, h, sy, sx, ey, ex;
vector<vector<char>> grid;
vector<vector<vector<ll>>> visited;

ll dy[4] = {0, 0, -1, 1};
ll dx[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> w >> h;
  grid.assign(h, vector<char>(w));
  sy = -1;
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'C') {
        if(sy == -1) {
          sy = i; sx = j;
        } else {
          ey = i; ex = j;
        }
      }
    }
  }

  visited.resize(4);
  for_each(visited.begin(), visited.end(), [](auto& layer) { 
    layer.assign(h, vector<ll>(w, INF));
  });

  queue<tuple<ll, ll, ll>> q;
  for(ll k = 0; k < 4; k++) {
    visited[k][sy][sx] = 0;
    q.push({k, sy, sx});
  }

  while(q.size()) {
    auto [d, y, x] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny < 0 || ny >= h || nx < 0 || nx >= w || grid[ny][nx] == '*') continue;
      if(d == k) {
        if(visited[k][ny][nx] > visited[d][y][x]) {
          visited[k][ny][nx] = visited[d][y][x];
          q.push({k, ny, nx});
        }
      } else {
        if(visited[k][ny][nx] > visited[d][y][x] + 1) {
          visited[k][ny][nx] = visited[d][y][x] + 1;
          q.push({k, ny, nx});
        }
      }
    }
  }

  ll answer = INF;
  for(ll i = 0; i < 4; i++) {
    answer = min(answer, visited[i][ey][ex]);
  }

  cout << answer << '\n';
  
  return 0;
}