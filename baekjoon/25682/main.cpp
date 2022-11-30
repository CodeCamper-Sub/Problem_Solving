#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll m, n, k, minimum;
char c;
ll grid[2020][2020]; // black = 0 / white = 1
ll black_p_sum[2020][2020], white_p_sum[2020][2020];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  minimum = INF;
  cin >> n >> m >> k;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= m; j++) {
      cin >> c;
      if(c == 'B') { grid[i][j] = 0; }
      else { grid[i][j] = 1; }
    }
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= m; j++) {
      if((i + j) % 2 == 0) {
        if(grid[i][j] == 0) {
          black_p_sum[i][j] = 0;
          white_p_sum[i][j] = 1;
        } else {
          black_p_sum[i][j] = 1;
          white_p_sum[i][j] = 0;
        }
      } else {
        if(grid[i][j] == 0) {
          black_p_sum[i][j] = 1;
          white_p_sum[i][j] = 0;
        } else {
          black_p_sum[i][j] = 0;
          white_p_sum[i][j] = 1;
        }
      }
    }
  }
  for(ll i = 1; i <= n; i++) {
    for(ll j = 2; j <= m; j++) {
      black_p_sum[i][j] = black_p_sum[i][j] + black_p_sum[i][j-1];
      white_p_sum[i][j] = white_p_sum[i][j] + white_p_sum[i][j-1];
    }
  }
  for(ll j = 1; j <= m; j++) {
    for(ll i = 2; i <= n; i++) {
      black_p_sum[i][j] = black_p_sum[i][j] + black_p_sum[i-1][j];
      white_p_sum[i][j] = white_p_sum[i][j] + white_p_sum[i-1][j];
    }
  }

  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= m; j++) {
      if(i - k >= 0 && j - k >= 0) {
        ll partial_solution;
        // black
        partial_solution = black_p_sum[i][j] - black_p_sum[i-k][j] - black_p_sum[i][j-k] + black_p_sum[i-k][j-k];
        minimum = min(minimum, partial_solution);

        // white
        partial_solution = white_p_sum[i][j] - white_p_sum[i-k][j] - white_p_sum[i][j-k] + white_p_sum[i-k][j-k];
        minimum = min(minimum, partial_solution);
      }
    }
  }

  cout << minimum << '\n';

  return 0;
}