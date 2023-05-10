#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<vector<ll>> grid;
vector<ll> cnt;

bool is_ok(ll y, ll x, ll side) {
  for(ll i = 0; i < side; i++) {
    for(ll j = 0; j < side; j++) {
      ll ny = y + i;
      ll nx = x + j;
      if(ny < 0 || ny >= 10 || nx < 0 || nx >= 10 || grid[ny][nx] == 0) return false;
    }
  }
  return true;
}

ll backtracking(ll now) {
  if(now == 100) return 0;
  ll result = INF;
  ll y = now / 10;
  ll x = now % 10;
  if(grid[y][x] == 0) return backtracking(now + 1);
  for(ll i = 1; i <= 5; i++) {
    if(cnt[i] == 0) continue;
    if(is_ok(y, x, i)) {
      for(ll j = 0; j < i; j++) {
        for(ll k = 0; k < i; k++) {
          grid[y + j][x + k] = 0;
        }
      }
      cnt[i]--;
      result = min(result, 1 + backtracking(now + 1));
      for(ll j = 0; j < i; j++) {
        for(ll k = 0; k < i; k++) {
          grid[y + j][x + k] = 1;
        }
      }
      cnt[i]++;
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cnt.assign(6, 5);
  grid.assign(10, vector<ll>(10));

  for(ll i = 0; i < 10; i++) {
    for(ll j = 0; j < 10; j++) {
      cin >> grid[i][j];
    }
  }

  ll answer = backtracking(0);

  if(answer == INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }
  
  return 0;
}