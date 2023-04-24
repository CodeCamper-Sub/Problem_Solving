#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll r1, c1, r2, c2;

ll a(ll i) {  // {-i, i}
  return 4 * i * i - 2 * i + 1;
}

ll b(ll i) {  // {-i, -i}
  return 4 * i * i + 1;
}

ll c(ll i) { // {i, -i}
  return 4 * i * i + 2 * i + 1;
}

ll d(ll i) { // {i, i};
  return 4 * i * i + 4 * i + 1;
}

ll value(ll y, ll x) {
  if(y == 0 && x == 0) return 1;
  ll d = max(abs(y), abs(x));
  if(-y == d) {
    return a(d) + d - x;
  } else if(-x == d) {
    return b(d) + y + d;
  } else if(y == d) {
    return c(d) + x + d;
  } else {
    return a(d) - (d + y);
  }
}

vector<vector<ll>> grid;
ll maxi = 0, length = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> r1 >> c1 >> r2 >> c2;
  grid.assign(r2 - r1 + 1, vector<ll>(c2 - c1 + 1));
  for(ll i = 0; i <= r2 - r1; i++) {
    for(ll j = 0; j <= c2 - c1; j++) {
      grid[i][j] = value(r1 + i, c1 + j);
      maxi = max(maxi, grid[i][j]);
    }
  }

  length = log10(maxi) + 1;
  for_each(grid.begin(), grid.end(), [](auto& row) {
    for(ll i = 0; i < row.size(); i++) {
      cout.width(length);
      cout << row[i];
      cout.width(1);
      cout << ' ';
    }
    cout << '\n';
  });
  
  return 0;
}