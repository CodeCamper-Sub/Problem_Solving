#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<vector<char>> grid;

void draw(ll y, ll x, ll height) {
  if(height == 3) {
    grid[y][x + 2] = '*';
    grid[y + 1][x + 1] = '*';
    grid[y + 1][x + 3] = '*';
    for(ll i = 0; i < 5; i++) grid[y + 2][x + i] = '*';
    return;
  }
  draw(y, x + height / 2, height / 2);
  draw(y + height / 2, x, height / 2);
  draw(y + height / 2, x + height, height / 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  grid.assign(n + 1, vector<char>(2 * n, ' '));
  draw(0, 0, n);
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < 2 * n; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
  
  return 0;
}