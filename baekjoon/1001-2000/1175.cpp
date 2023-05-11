#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, sy, sx, cy1, cx1, cy2, cx2;
vector<vector<char>> grid;
vector<vector<vector<ll>>> visited;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

void bfs(ll sy, ll sx, ll sd, ll ey, ll ex) {
  visited.resize(4);
  for_each(visited.begin(), visited.end(), [](auto& layer){
    layer.assign(n, vector<ll>(m, INF));
  });
  queue<tuple<ll, ll, ll>> q;
  q.push({sy, sx, sd});
  if(sd != -1) {
    visited[sd][sy][sx] = 0;
  }
  while(q.size()) {
    auto [y, x, d] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      if(k == d) continue;
      ll ny = y + dy[k], nx = x + dx[k], nd = k;
      if(ny < 0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == '#') continue;
      if(d == -1) {
        visited[nd][ny][nx] = 1;
        q.push({ny, nx, nd});
      } else if(visited[nd][ny][nx] > visited[d][y][x] + 1) {
        visited[nd][ny][nx] = visited[d][y][x] + 1;
        q.push({ny, nx, nd});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<char>(m));

  cy1 = -1; cx1 = -1;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> grid[i][j];
      if(grid[i][j] == 'S') {
        sy = i; sx = j;
      } else if(grid[i][j] == 'C') {
        if(cy1 == -1 && cx1 == -1) {
          cy1 = i; cx1 = j;
        } else {
          cy2 = i; cx2 = j;
        }
      }
    }
  }

  ll answer = INF;
  // S -> C1 -> C2
  bfs(sy, sx, -1, cy1, cx1);
  vector<ll> ncost;
  for(ll k = 0; k < 4; k++) {
    ncost.push_back(visited[k][cy1][cx1]);
  }
  for(ll k = 0; k < 4; k++) {
    if(ncost[k] == INF) continue;
    bfs(cy1, cx1, k, cy2, cx2);
    for(ll j = 0; j < 4; j++) {
      if(visited[j][cy2][cx2] == INF) continue;
      answer = min(answer, ncost[k] + visited[j][cy2][cx2]);
    }
  }

  // S -> C2 -> C1
  bfs(sy, sx, -1, cy2, cx2);
  ncost.clear();
  for(ll k = 0; k < 4; k++) {
    ncost.push_back(visited[k][cy2][cx2]);
  }
  for(ll k = 0; k < 4; k++) {
    if(ncost[k] == INF) continue;
    bfs(cy2, cx2, k, cy1, cx1);
    for(ll j = 0; j < 4; j++) {
      if(visited[j][cy1][cx1] == INF) continue;
      answer = min(answer, ncost[k] + visited[j][cy1][cx1]);
    }
  }

  if(answer >= INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}