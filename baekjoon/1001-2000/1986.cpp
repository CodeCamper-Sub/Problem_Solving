#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, m, t, y, x;
vector<vector<bool>> is_ok;
vector<vector<char>> grid;
vector<pair<ll, ll>> queens, knights;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n + 1, vector<char>(m + 1, '.'));
  is_ok.assign(n + 1, vector<bool>(m + 1, true));
  
  cin >> t;
  while(t--) {
    cin >> y >> x;
    grid[y][x] = 'Q';
    is_ok[y][x] = false;
    queens.push_back({y, x});
  }
  cin >> t;
  while(t--) { 
    cin >> y >> x;
    grid[y][x] ='K';
    is_ok[y][x] = false;
    knights.push_back({y, x});
  }
  cin >> t;
  while(t--) {
    cin >> y >> x;
    is_ok[y][x] = false;
    grid[y][x] = 'P';
  }

  ll qdy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
  ll qdx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
  for(auto [y, x]: queens) {
    for(ll k = 0; k < 8; k++) {
      ll d = 0;
      while(++d) {
        ll ny = y + qdy[k] * d;
        ll nx = x + qdx[k] * d;
        if(!ny || ny > n || !nx || nx > m || grid[ny][nx] != '.') break;
        is_ok[ny][nx] = false;
      }
    }
  }

  ll kdy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  ll kdx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  for(auto [y, x]: knights) {
    for(ll k = 0; k < 8; k++) {
      ll ny = y + kdy[k];
      ll nx = x + kdx[k];
      if(ny <= 0 || ny > n || nx <= 0 || nx > m || grid[ny][nx] != '.') continue;
      is_ok[ny][nx] = false;
    }
  }

  ll answer = 0;
  for(ll i = 1; i <= n; i++) for(ll j = 1; j <= m; j++) {
    if(is_ok[i][j]) answer++;
  }

  cout << answer << '\n';

  return 0;
}