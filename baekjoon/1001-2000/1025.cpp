#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, m, answer;
vector<vector<ll>> grid;

bool is_square(ll now) {
  ll sqrtNow = sqrt(now);
  return sqrtNow * sqrtNow == now;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  grid.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }
  answer = -1;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      for(ll a = -n + 1; a < n; a++) {
        for(ll b = -m + 1; b < m; b++) {
          ll now = 0;
          for(ll k = 0; k < max(n, m); k++) {
            ll y = i + a * k;
            ll x = j + b * k;
            if(y < 0 || y >= n || x < 0 || x >= m) break;
            now *= 10;
            now += grid[y][x];
            if(is_square(now)) {
              answer = max(answer, now);
            }
          }
        }
      }
    }
  }

  cout << answer << '\n';
  
  return 0;
}