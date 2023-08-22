#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m, k;
vector<vector<ll>> a, nut;
vector<vector<vector<ll>>> grid;
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m >> k;

  vector<vector<vector<ll>>> next;
  grid.assign(n, vector<vector<ll>>(n));
  next.assign(n, vector<vector<ll>>(n));
  a.assign(n, vector<ll>(n));
  nut.assign(n, vector<ll>(n, 5));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> a[i][j];

  while(m--) {
    ll x, y, z;
    cin >> y >> x >> z;
    x--; y--;
    grid[y][x].push_back(z);
  }

  while(k--) {
    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
      ll nnut = 0;
      while(grid[i][j].size()) {
        if(nut[i][j] >= grid[i][j].back()) {
          nut[i][j] -= grid[i][j].back();
          next[i][j].push_back(grid[i][j].back() + 1);
          grid[i][j].pop_back();
        } else {
          nnut += grid[i][j].back() / 2;
          grid[i][j].pop_back();
        }
      }
      nut[i][j] += nnut;

      while(next[i][j].size()) {
        grid[i][j].push_back(next[i][j].back());
        next[i][j].pop_back();
      }
    }

    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
      while(grid[i][j].size()) {
        if(grid[i][j].back() % 5 == 0) {
          for(ll k = 0; k < 8; k++) {
            ll ny = i + dy[k], nx = j + dx[k];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            next[ny][nx].push_back(1);
          }
        }
        next[i][j].push_back(grid[i][j].back());
        grid[i][j].pop_back();
      }
    }

    for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
      while(next[i][j].size()) {
        grid[i][j].push_back(next[i][j].back());
        next[i][j].pop_back();
      }
      sort(grid[i][j].begin(), grid[i][j].end(), greater<>());
      nut[i][j] += a[i][j];
    }
  }

  ll answer = 0;
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) answer += grid[i][j].size();

  cout << answer << '\n';

  
  return 0;
}