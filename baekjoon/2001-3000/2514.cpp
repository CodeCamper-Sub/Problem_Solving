#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll m, k;
vector<vector<ll>> grid(8, vector<ll>(8)), fert_grid(8, vector<ll>(8)), answer(8, vector<ll>(8));
vector<ll> row(8, 0), col(8, 0), fert_row(8, 0), fert_col(8, 0);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> m >> k;
  for(ll i = 0; i < 8; i++) {
    for(ll j = 0; j < 8; j++) {
      cin >> grid[i][j];
      grid[i][j] -= m;
      row[i] += grid[i][j];
      col[j] += grid[i][j];
    }
  }

  for(ll i = 0; i < 8; i++) {
    for(ll j = 0; j < 8; j++) {
      if((row[i] + col[j] - grid[i][j]) % 2) {
        for(ll k = 0; k < 8; k++) {
          fert_grid[i][k]++;
          fert_row[i]++; fert_col[k]++;
          if(k != i) {
            fert_grid[k][j]++;
            fert_row[k]++; fert_col[j]++;
          }
        }
      }
    }
  }

  for(ll i = 0; i < 8; i++) {
    for(ll j = 0; j < 8; j++) {
      if((row[i] + col[j] - grid[i][j]) % 2 == 0) continue;
      ll delta = abs((row[i] + col[j] - grid[i][j]) - (fert_row[i] + fert_col[j] - fert_grid[i][j]));
      if(delta % 4 == 2) {
        // 제초기
        answer[i][j] = -1;
      } else {
        // 비료액
        answer[i][j] = 1;
      }
    }
  }

  for(ll i = 0; i < 8; i++) {
    for(ll j = 0; j < 8; j++) {
      if(answer[i][j] == 1) {
        cout << '+';
      } else if(answer[i][j] == 0) {
        cout << '.';
      } else {
        cout << '-';
      }
      cout << ' ';
    }
    cout << '\n';
  }


  
  return 0;
}