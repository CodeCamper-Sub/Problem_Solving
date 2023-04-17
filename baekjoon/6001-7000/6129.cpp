#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 110
typedef long long ll;
using namespace std;

enum Direction {
  E,
  W,
  S,
  N
};

ll n, ay, ax, by, bx, visited[MAX][MAX][4];
char grid[MAX][MAX];
bool in_queue[MAX][MAX][4];
queue<tuple<ll, ll, Direction>> q;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};
Direction directions[4] = {E, W, S, N};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll y = 0; y < n; y++) {
    for(ll x = 0; x < n; x++) {
      cin >> grid[y][x];
      if(grid[y][x] == 'A') {
        ay = y;
        ax = x;
      } else if(grid[y][x] == 'B') {
        by = y;
        bx = x;
      }
    }
  }

  fill(&visited[0][0][0], &visited[MAX - 1][MAX - 1][4], INF);
  visited[ay][ax][E] = 0;
  in_queue[ay][ax][E] = true;
  q.push({ay, ax, E});
  visited[ay][ax][W] = 0;
  in_queue[ay][ax][W] = true;
  q.push({ay, ax, W});
  visited[ay][ax][S] = 0;
  in_queue[ay][ax][S] = true;
  q.push({ay, ax, S});
  visited[ay][ax][N] = 0;
  in_queue[ay][ax][N] = true;
  q.push({ay, ax, N});

  while(q.size()) {
    auto [y, x, d] = q.front();
    q.pop();
    in_queue[y][x][d] = false;
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      Direction nd = directions[k];
      ll cost = nd == d ? 0 : 1;
      if(ny < n && ny >= 0 && nx < n && nx >= 0 && grid[ny][nx] != 'x' && visited[ny][nx][nd] > visited[y][x][d] + cost) {
        visited[ny][nx][nd] = visited[y][x][d] + cost;
        if(!in_queue[ny][nx][nd]) {
          in_queue[ny][nx][nd] = true;
          q.push({ny, nx, nd});
        }
      }
    }
  }

  ll answer = INF;
  for(ll d = 0; d < 4; d++) {
    answer = min(answer, visited[by][bx][d]);
  }

  cout << answer << '\n';

  return 0;
}