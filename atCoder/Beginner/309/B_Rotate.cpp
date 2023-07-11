#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

vector<vector<ll>> grid, answer;
ll n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  grid.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++) {
    char c;
    cin >> c;
    grid[i][j] = c - '0';
  }
  answer = grid;
  for(ll i = 0; i < n - 1; i++) {
    answer[i][0] = grid[i + 1][0];
    answer[n - 1][i] = grid[n - 1][i + 1];
  }
  for(ll i = 1; i < n; i++) {
    answer[0][i] = grid[0][i - 1];
    answer[i][n - 1] = grid[i - 1][n - 1];
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cout << answer[i][j];
    }
    cout << '\n';
  }
  
  return 0;
}