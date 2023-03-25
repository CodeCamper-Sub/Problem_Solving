#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll h, w, answer;
ll grid[20][20], visited[20][20];
set<ll> path;
ll dx[2] = {1, 0};
ll dy[2] = {0, 1};

bool is_ok(ll y, ll x) {
    if(y >= h || x >= w || path.find(grid[y][x]) != path.end() || visited[y][x]) return false;
    return true;
}

void dfs(ll y, ll x) {
    if(y == h - 1 && x == w - 1) { 
        answer++;
        return;
    }
    for(ll k = 0; k < 2; k++) {
        ll ny = y + dy[k];
        ll nx = x + dx[k];
        if(is_ok(ny, nx)) {
            path.insert(grid[ny][nx]);
            visited[ny][nx] = true;
            dfs(ny, nx);
            visited[ny][nx] = false;
            path.erase(grid[ny][nx]);
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;
  for(ll i = 0; i < h; i++) {
    for(ll j = 0; j < w; j++) {
        cin >> grid[i][j];
    }
  }

  path.insert(grid[0][0]);
  visited[0][0] = true;
  dfs(0, 0);

  cout << answer << '\n';
  
  return 0;
}