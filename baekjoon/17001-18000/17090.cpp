#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll dy[4] = {-1, 0, 1, 0};
ll dx[4] = {0, 1, 0, -1};
ll r, c;
vector<vector<char>> grid;
vector<vector<ll>> visited;

ll char_to_direction(char c) {
  if(c == 'U') return 0;
  else if(c == 'R') return 1;
  else if(c == 'D') return 2;
  else return 3;
}

ll dfs(ll y, ll x) {
  ll nd = char_to_direction(grid[y][x]);
  ll ny = y + dy[nd], nx = x + dx[nd];
  if(ny < 0 || ny >= r || nx < 0 || nx >= c) return visited[y][x] = 1;
  if(visited[ny][nx] != -1) return visited[y][x] = visited[ny][nx];
  else {
    visited[y][x] = 0;
    return visited[y][x] = dfs(ny, nx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r >> c;
  grid.assign(r, vector<char>(c));
  for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) cin >> grid[i][j];
  visited.assign(r, vector<ll>(c, -1));
  for(ll i = 0; i < r; i++) {
    for(ll j = 0; j < c; j++) {
      if(visited[i][j] == -1) dfs(i, j);
    }
  }

  ll answer = 0;
  for(ll i = 0; i < r; i++) for(ll j = 0; j < c; j++) {
    if(visited[i][j] == 1) answer++;
  }
  cout << answer << '\n';
  
  return 0;
}