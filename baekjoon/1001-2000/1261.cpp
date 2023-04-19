#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m;
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};
vector<vector<ll>> visited;
vector<vector<ll>> grid;
queue<pair<ll, ll>> q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> n;
  visited.assign(n, vector<ll>(m, INF));
  grid.assign(n, vector<ll>(m, 0));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) {
    char c;
    cin >> c;
    grid[i][j] = c - '0';
  } 


  visited[0][0] = 0;
  q.push({0, 0});
  while(q.size()) {
    auto [y, x] = q.front();
    q.pop();
    for(ll k = 0; k < 4; k++) {
      ll ny = y + dy[k], nx = x + dx[k];
      if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
      if(grid[ny][nx] && visited[ny][nx] > visited[y][x] + 1) {
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny, nx});
      } else if(!grid[ny][nx] && visited[ny][nx] > visited[y][x]) {
        visited[ny][nx] = visited[y][x];
        q.push({ny, nx});
      }
    }
  }

  cout << visited[n - 1][m - 1] << '\n';
  
  return 0;
}