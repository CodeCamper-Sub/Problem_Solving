#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, l;
vector<vector<ll>> grid;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> l;
  grid.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) cin >> grid[i][j];

  ll answer = 0;
  // 행
  for(ll i = 0; i < n; i++) {
    ll cnt = 1;
    bool is_valid = true;
    for(ll j = 0; j < n - 1; j++) {
      if(grid[i][j] == grid[i][j + 1]) cnt++;
      else if(grid[i][j] + 1 == grid[i][j + 1]) {
        if(cnt >= l) cnt = 1;
        else {
          is_valid = false;
          break;
        }
      } else if(grid[i][j] - 1 == grid[i][j + 1]) {
        if(j + l >= n) {
          is_valid = false;
          break;
        }
        for(ll k = 1; k < l; k++) {
          if(grid[i][j + k] != grid[i][j + k + 1]) {
            is_valid = false;
            break;
          }
        }
        if(!is_valid) break;
        j += l - 1;
        cnt = 0;
      } else {
        is_valid = false;
        break;
      }
    }
    if(is_valid) answer++;
  }

  // 열
  for(ll j = 0; j < n; j++) {
    ll cnt = 1;
    bool is_valid = true;
    for(ll i = 0; i < n - 1; i++) {
      if(grid[i][j] == grid[i + 1][j]) cnt++;
      else if(grid[i][j] + 1 == grid[i + 1][j]) {
        if(cnt >= l) cnt = 1;
        else {
          is_valid = false;
          break;
        }
      } else if(grid[i][j] - 1 == grid[i + 1][j]) {
        if(i + l >= n) {
          is_valid = false;
          break;
        }
        for(ll k = 1; k < l; k++) {
          if(grid[i + k][j] != grid[i + k + 1][j]) {
            is_valid = false;
            break;
          }
        }
        if(!is_valid) break;
        i += l - 1;
        cnt = 0;
      } else {
        is_valid = false;
        break;
      }
    }
    if(is_valid) answer++;
  }

  cout << answer << '\n';
  
  return 0;
}