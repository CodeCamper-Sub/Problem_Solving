#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll h, w, t, id, sy, sx, ey, ex, answer;
vector<vector<ll>> grid;
vector<vector<ll>> visited, dist;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

ll solve() {
  vector<vector<ll>> visited;
  visited.assign((1ll << id), vector<ll>(id, INF));
  queue<pair<ll, ll>> q;
  visited[(1ll << 1)][1] = 0;
  q.push({1ll << 1, 1});
  while(q.size()) {
    auto [status, now] = q.front();
    q.pop();
    for(ll next = 2; next < id; next++) {
      if((1ll << next) & status) continue;
      if(visited[status][now] + dist[now][next] > t) continue;
      if(visited[status | (1ll << next)][next] > visited[status][now] + dist[now][next]) {
        visited[status | (1ll << next)][next] = visited[status][now] + dist[now][next];
        if(next != id - 1) {
          q.push({status | (1ll << next), next});
        }
      }
    }
  }
  answer = -INF;
  for(ll i = 0; i < (1ll << id); i++) {
    if(visited[i][id - 1] != INF) {
      ll candy_cnt = 0;
      for(ll j = 0; j < id; j++) {
        if((1ll << j) & i) candy_cnt++;
      }
      answer = max(answer, candy_cnt - 2);
    }
  }
  if(answer == -INF) return -1;
  else return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> h >> w >> t;
  grid.assign(h, vector<ll>(w));
  id = 2;
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
      char c;
      cin >> c;
      if(c == 'o') {
        grid[i][j] = id++;
      } else if(c == 'S') {
        sy = i; sx = j;
      } else if(c == 'G') {
        ey = i; ex = j;
      } else if(c == '.') {
        grid[i][j] = 0;
      } else {
        grid[i][j] = -1;
      }
    }
  }

  grid[sy][sx] = 1;
  grid[ey][ex] = id++;

  dist.assign(id, vector<ll>(id, INF));
  for(ll i = 1; i < id; i++) {
    ll y = -1, x = -1;
    for(ll j = 0; j < h; j++) {
      for(ll k = 0; k < w; k++) {
        if(grid[j][k] == i) {
          y = j;
          x = k;
          break;
        }
      }
      if(y != -1) break;
    }
    visited.assign(h, vector<ll>(w, INF));
    visited[y][x] = 0;
    queue<pair<ll, ll>> q;
    q.push({y, x});
    while(q.size()) {
      auto [y, x] = q.front();
      q.pop();
      if(grid[y][x] > 0) {
        dist[i][grid[y][x]] = visited[y][x];
      }
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny >= 0 && ny < h && nx >= 0 && nx < w && grid[ny][nx] != -1 && visited[ny][nx] > visited[y][x] + 1) {
          visited[ny][nx] = visited[y][x] + 1;
          q.push({ny, nx});
        }
      }
    }
  }

   

  cout << solve() << '\n';
  
  return 0;
}