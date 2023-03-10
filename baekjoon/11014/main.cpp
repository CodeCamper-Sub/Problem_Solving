#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 100
typedef long long ll;
using namespace std;

ll tt, n, m, occupied[MAX][MAX], visited[MAX][MAX], match_cnt, v_cnt;
bool grid[MAX][MAX];
ll dx[6] = {-1, -1, -1, 1, 1, 1};
ll dy[6] = {0, -1, 1, 0, -1, 1};

bool is_ok(ll y, ll x) {
  if(y >= n || y < 0 || x >= m || x < 0 || !grid[y][x]) return false;
  return true;
}

bool dfs(ll now) {
  ll nowy = now / m;
  ll nowx = now % m;
  for(ll k = 0; k < 6; k++) {
    ll nexty = nowy + dy[k];
    ll nextx = nowx + dx[k];
    if(!is_ok(nexty, nextx) || visited[nexty][nextx]) continue;
    visited[nexty][nextx] = true;
    if(occupied[nexty][nextx] == -1 || dfs(occupied[nexty][nextx])) {
      occupied[nexty][nextx] = now;
      return true;
    }
  }

  return false;
}

void solve() {
  fill(&occupied[0][0], &occupied[n][m], -1);
  match_cnt = 0;
  for(ll j = 0; j < m; j += 2) {
    for(ll i = 0; i < n; i++) {
      if(!is_ok(i, j)) continue;
      fill(&visited[0][0], &visited[n][m], false);
      if(dfs(i * m + j)) match_cnt++;
    }
  }

  #ifdef DEBUG
  cout << "\nAns: ";
  #endif
  cout << v_cnt - match_cnt << '\n';
}

void init() {
  cin >> n >> m;
  v_cnt = 0;
  for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) {
    char c;
    cin >> c;
    grid[i][j] = (c == '.');
    if(grid[i][j]) v_cnt++;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  
  return 0;
}